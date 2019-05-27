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

void 			set_model(t_data *data)
{
	identity(data->model);

	// fprintf(stdout, "\nmodel");
	// mat4_print(data->model);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, data->model);
}

void			set_view(t_data *data)
	{
	identity(data->view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;

	coord_to_vec(0.0f, 2.0f, 5.0f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 1, 0, up);

	lookat(eye, target, up, data->view);
	
	// fprintf(stdout, "\nview");
	// mat4_print(data->view);

	GLint uniView = glGetUniformLocation(data->shader.program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, data->view);
}

void			set_proj(t_data *data)
{
	identity(data->proj);

	float		planes[2];
	float		vfov;
	float		ratio;

	vfov = deg_to_rad(60.0f);
	ratio = 800.0f / 600.0f;
	planes[NEAR_PLANE] = 1.0f;
	planes[FAR_PLANE] = 10.0f;

	perspective(vfov, ratio, planes, data->proj);

	// fprintf(stdout, "\nproj");
	// mat4_print(data->proj);

	GLint uniProj = glGetUniformLocation(data->shader.program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, data->proj);
}
