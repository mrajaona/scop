#include "process_model.h"

static int		vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
	return (1);
}

static t_vector_ptr	get_triangle_normal(t_triangle *triangle)
{
	t_vector	va;
	t_vector	vb;

	vector_sub(triangle->v2, triangle->v1, va);
	vector_sub(triangle->v3, triangle->v1, vb);

	coord_cross_prod(va, vb, triangle->normal);
	coord_normalize(triangle->normal, triangle->normal);

	return (triangle->normal);
}

static t_vector_ptr	get_vertex(const t_model *model, GLuint index)
{
	t_list	*list;

	list = model->vertices;
	while (list && list->index != index)
		list = list->next;
	if (!list)
		return (NULL);
	return ((t_vector_ptr)(list->data));
}

static void			cpy_vertice(t_coord dest, t_coord coord, t_coord normal)
{
	coord_eq(dest, coord);
	coord_eq(dest + 3, normal);
}

/*
** place all points in space
** pos		tex
** x y z	u v
*/

static int		vbo(GLuint *vbo, const t_model *model)
{
	t_list			*list;
	size_t			size;
	float			*vertices;
	float			*vertice;
	t_triangle		triangle;

	size = model->nfaces * N_VERTICES_PER_FACE * N_DATA_PER_VERTICE;
	if (!(vertices = (float *)malloc(size * sizeof(float))))
		return (0);
	vertice = vertices;

	clear_vector(triangle.v1);
	clear_vector(triangle.v2);
	clear_vector(triangle.v3);

	list = model->faces;
	while (list)
	{
		coord_eq(triangle.v1, get_vertex(model, ((GLuint *)(list->data))[0]));
		coord_eq(triangle.v2, get_vertex(model, ((GLuint *)(list->data))[1]));
		coord_eq(triangle.v3, get_vertex(model, ((GLuint *)(list->data))[2]));
		get_triangle_normal(&triangle);

		cpy_vertice(vertice + (0 * N_DATA_PER_VERTICE), triangle.v1, triangle.normal);
		cpy_vertice(vertice + (1 * N_DATA_PER_VERTICE), triangle.v2, triangle.normal);
		cpy_vertice(vertice + (2 * N_DATA_PER_VERTICE), triangle.v3, triangle.normal);

		vertice += N_VERTICES_PER_FACE * N_DATA_PER_VERTICE;

		list = list->next;
	}

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW); // copy the vertex data

	free(vertices);
	return (1);
}

int				process_model(const t_model *model, t_data *data)
{
	GLint pos_attrib;
	// GLint tex_attrib;
	data->nfaces = model->nfaces;

	if (!vao(&(data->model.arrays.vao)))
		return (0);
	if (!vbo(&(data->model.arrays.vbo), model))
		return (0);

	pos_attrib = glGetAttribLocation(data->model.shader.program, "position");
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE,
		N_DATA_PER_VERTICE * sizeof(float), 0);
	glEnableVertexAttribArray(pos_attrib);

	pos_attrib = glGetAttribLocation(data->model.shader.program, "normal");
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE,
		N_DATA_PER_VERTICE * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(pos_attrib);
	/*
	tex_attrib = glGetAttribLocation(data->model.shader.program, "texcoord");
	glVertexAttribPointer(tex_attrib, 2, GL_FLOAT, GL_FALSE,
		N_DATA_PER_VERTICE * sizeof(float, (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(tex_attrib);
	*/

	use_no_model();

	return (1);
}