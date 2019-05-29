#include "process_model.h"

static int		vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
	return (1);
}

/*
** place all points in space
** pos		tex
** x y z	u v
*/

static int		vbo(GLuint *vbo, const t_model *model)
{
	t_list			*list;
	unsigned int	i;
	size_t			size;
	float			*vertices;
	float			*vertice;

	size = model->nvertices * N_DATA_PER_VERTICE;
	if (!(vertices = (float *)malloc(size * sizeof(float))))
		return (0);
	list = model->vertices;
	vertice = vertices;
	while (list)
	{
		i = 0;
		while (i < N_DATA_PER_VERTICE)
		{
			vertice[i] = ((float *)(list->data))[i];
			i++;
		}
		list = list->next;
		vertice += N_DATA_PER_VERTICE;
	}

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW); // copy the vertex data

	free(vertices);
	return (1);
}

/*
** link points in order
** indices
*/

static int		ibo(GLuint *ibo, const t_model *model)
{
	
	t_list			*list;
	unsigned int	i;
	size_t			size;
	GLuint			*elements;
	GLuint			*element;

	size = model->nfaces * N_VERTICES_PER_FACE;
	if (!(elements = (GLuint *)malloc(size * sizeof(GLuint))))
		return (0);
	list = model->faces;
	element = elements;
	while (list)
	{
		i = 0;
		while (i < N_VERTICES_PER_FACE)
		{
			element[i] = ((GLuint *)(list->data))[i];
			i++;
		}
		list = list->next;
		element += N_VERTICES_PER_FACE;
	}

	glGenBuffers(1, ibo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo); // make active
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, elements,
		GL_STATIC_DRAW);

	free(elements);
	return (1);
}

int				process_model(const t_model *model, t_data *data)
{
	data->nfaces = model->nfaces;

	if (!vao(&(data->arrays_model.vao)))
		return (0);
	if (!vbo(&(data->arrays_model.vbo), model))
		return (0);
	if (!ibo(&(data->arrays_model.ibo), model))
		return (0);
	
	GLint pos_attrib;
	// GLint tex_attrib;

	pos_attrib = glGetAttribLocation(data->shader.program, "position");
	glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE,
		N_DATA_PER_VERTICE * sizeof(float), 0);
	glEnableVertexAttribArray(pos_attrib);
	/*
	tex_attrib = glGetAttribLocation(data->shader.program, "texcoord");
	glVertexAttribPointer(tex_attrib, 2, GL_FLOAT, GL_FALSE,
		5 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(tex_attrib);
	*/

	glBindVertexArray(0);

	return (1);
}