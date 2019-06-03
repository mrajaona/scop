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

void 			set_model(t_data *data)
{
	GLint		uniModel;

	identity(data->model.mat_model);

	mat4_rotatey(deg_to_rad(90.0f), data->model.mat_model);

	// fprintf(stdout, "\nmodel");
	// mat4_print(data->mat_model);

	use_model(&(data->model));

	uniModel = glGetUniformLocation(data->model.shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, data->model.mat_model);

	use_no_model();
}

void 			set_light(t_data *data)
{
	GLint		uniModel;

	use_model(&(data->model));

	coord_to_vec(4.0f, 1.0f, 4.0f, data->light.position);
	coord_to_vec(1.0f, 1.0f, 1.0f, data->light.color);
	coord_to_vec(0.2f, 0.2f, 0.2f, data->light.ambient);
	coord_to_vec(0.5f, 0.5f, 0.5f, data->light.diffuse);
	coord_to_vec(1.0f, 1.0f, 1.0f, data->light.specular);

	uniModel = glGetUniformLocation(data->model.shader.program, "light.position");
	glUniform3fv(uniModel, 1, data->light.position);
	uniModel = glGetUniformLocation(data->model.shader.program, "light.color");
	glUniform3fv(uniModel, 1, data->light.color);
	uniModel = glGetUniformLocation(data->model.shader.program, "light.ambient");
	glUniform3fv(uniModel, 1, data->light.ambient);
	uniModel = glGetUniformLocation(data->model.shader.program, "light.diffuse");
	glUniform3fv(uniModel, 1, data->light.diffuse);
	uniModel = glGetUniformLocation(data->model.shader.program, "light.specular");
	glUniform3fv(uniModel, 1, data->light.specular);

	use_no_model();
}

void			set_view(t_data *data)
	{
	identity(data->mat_view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;
	GLint		uniView;

	coord_to_vec(5.0f, 5.0f, 0.0f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);

	lookat(eye, target, up, data->mat_view);
	
	// fprintf(stdout, "\nview");
	// mat4_print(data->mat_view);

	use_model(&(data->model));
	uniView = glGetUniformLocation(data->model.shader.program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, data->mat_view);

	uniView = glGetUniformLocation(data->model.shader.program, "viewPos");
	glUniform3fv(uniView, 1, eye);

	use_no_model();
}

void			set_proj(t_data *data)
{
	identity(data->mat_proj);

	float		planes[2];
	float		vfov;
	float		ratio;
	GLint		uniProj;

	vfov = deg_to_rad(80.0f);
	ratio = 800.0f / 600.0f;
	planes[NEAR_PLANE] = 0.001f;
	planes[FAR_PLANE] = 100.0f;

	perspective(vfov, ratio, planes, data->mat_proj);

	// fprintf(stdout, "\nproj");
	// mat4_print(data->mat_proj);

	use_model(&(data->model));
	uniProj = glGetUniformLocation(data->model.shader.program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, data->mat_proj);

	use_no_model();
}
