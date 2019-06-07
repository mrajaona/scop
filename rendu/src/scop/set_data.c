/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:17 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:18 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_data.h"
#include "mat4_rotate.h"

void			set_model(t_data *data)
{
	GLint		uni_model;

	identity(data->model.mat_model);
	use_model(&(data->model));
	uni_model = glGetUniformLocation(data->model.shader.program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, data->model.mat_model);
	use_no_model();
}

void			set_light(t_data *data)
{
	GLint		uni_model;

	use_model(&(data->model));
	coord_to_vec(0.0f, 0.0f, 5.0f, data->light.position);
	coord_to_vec(1.0f, 1.0f, 1.0f, data->light.color);
	coord_to_vec(0.3f, 0.3f, 0.3f, data->light.ambient);
	coord_to_vec(0.7f, 0.7f, 0.7f, data->light.diffuse);
	coord_to_vec(1.0f, 1.0f, 1.0f, data->light.specular);
	uni_model = glGetUniformLocation(data->model.shader.program,
		"light.position");
	glUniform3fv(uni_model, 1, data->light.position);
	uni_model = glGetUniformLocation(data->model.shader.program,
		"light.color");
	glUniform3fv(uni_model, 1, data->light.color);
	uni_model = glGetUniformLocation(data->model.shader.program,
		"light.ambient");
	glUniform3fv(uni_model, 1, data->light.ambient);
	uni_model = glGetUniformLocation(data->model.shader.program,
		"light.diffuse");
	glUniform3fv(uni_model, 1, data->light.diffuse);
	uni_model = glGetUniformLocation(data->model.shader.program,
		"light.specular");
	glUniform3fv(uni_model, 1, data->light.specular);
	use_no_model();
}

void			set_view(t_data *data)
{
	t_vector	eye;
	t_vector	target;
	t_vector	up;
	GLint		uni_view;

	identity(data->mat_view);
	coord_to_vec(0.0f, 0.0f, 5.0f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);
	lookat(eye, target, up, data->mat_view);
	use_model(&(data->model));
	uni_view = glGetUniformLocation(data->model.shader.program, "view");
	glUniformMatrix4fv(uni_view, 1, GL_FALSE, data->mat_view);
	uni_view = glGetUniformLocation(data->model.shader.program, "viewPos");
	glUniform3fv(uni_view, 1, eye);
	use_no_model();
}

void			set_proj(t_data *data)
{
	GLint		uni_proj;

	identity(data->mat_proj);
	perspective(data->mat_proj);
	use_model(&(data->model));
	uni_proj = glGetUniformLocation(data->model.shader.program, "proj");
	glUniformMatrix4fv(uni_proj, 1, GL_FALSE, data->mat_proj);
	use_no_model();
}
