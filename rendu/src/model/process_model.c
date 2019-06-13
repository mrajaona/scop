/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_model.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:51:19 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:51:19 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_model.h"

static int			vao(GLuint *vao)
{
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);
	return (1);
}

static t_vector_ptr	get_triangle_normal(t_triangle *triangle)
{
	t_vector	tmp_a;
	t_vector	tmp_b;

	vector_sub(triangle->v1, triangle->v2, tmp_a);
	vector_sub(triangle->v3, triangle->v2, tmp_b);
	coord_cross_prod(tmp_b, tmp_a, triangle->normal);
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

/*
** x y z
** nx ny nz
** u v
** r g b
*/

static void			cpy_vertice(float *dest, t_coord coord, t_coord normal,
	const t_model *model)
{
	static int		i = 0;
	static float	j = 0;

	coord_eq(dest, coord);
	coord_eq(dest + 3, normal);
	dest[6] = -1 * (coord[2] - model->min[2]);
	dest[7] = -1 * (coord[1] - model->min[1]);
	dest[8] = j;
	dest[9] = j;
	dest[10] = j;
	i = (i + 1) % 3;
	if (!i)
	{
		j += 0.25;
		if (j > 1)
			j = 0;
	}
}

/*
** place all points in space
** pos		tex
** x y z	u v
*/

static int			vbo(GLuint *vbo, const t_model *model)
{
	t_list			*list;
	size_t			size;
	float			*vertices;
	float			*face;
	t_triangle		triangle;

	size = model->nfaces * N_VERTICES_PER_FACE * N_DATA_PER_VERTICE;
	if (!(vertices = (float *)malloc(size * sizeof(float))))
		return (0);
	face = vertices;
	clear_vector(triangle.v1);
	clear_vector(triangle.v2);
	clear_vector(triangle.v3);
	list = model->faces;
	while (list)
	{
		memset((void *)face, 0,
			N_VERTICES_PER_FACE * N_DATA_PER_VERTICE * sizeof(float));
		coord_eq(triangle.v1, get_vertex(model, ((GLuint *)(list->data))[0]));
		coord_eq(triangle.v2, get_vertex(model, ((GLuint *)(list->data))[1]));
		coord_eq(triangle.v3, get_vertex(model, ((GLuint *)(list->data))[2]));
		get_triangle_normal(&triangle);
		cpy_vertice(face + (0 * N_DATA_PER_VERTICE),
			triangle.v1, triangle.normal, model);
		cpy_vertice(face + (1 * N_DATA_PER_VERTICE),
			triangle.v2, triangle.normal, model);
		cpy_vertice(face + (2 * N_DATA_PER_VERTICE),
			triangle.v3, triangle.normal, model);
		face += N_VERTICES_PER_FACE * N_DATA_PER_VERTICE;
		list = list->next;
	}
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices,
		GL_STATIC_DRAW);
	free(vertices);
	return (1);
}

int					process_model(const t_model *model, t_data *data)
{
	coord_to_vec(
		(model->min[0] + model->max[0]) / 2,
		(model->min[1] + model->max[1]) / 2,
		(model->min[2] + model->max[2]) / 2,
		data->model.center);
	data->model.nfaces = model->nfaces;
	if (!vao(&(data->model.arrays.vao)))
		return (0);
	if (!vbo(&(data->model.arrays.vbo), model))
		return (0);
	set_attribs(data->model.shader.program, model);
	use_no_model();
	return (1);
}
