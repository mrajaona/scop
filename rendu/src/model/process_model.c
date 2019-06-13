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
