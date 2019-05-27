/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:38 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:39 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show.h"

static void		edit_output(const t_data *data, t_mat4 model)
{
	static int	deg = 0;
	GLint		uni_model;

	deg = (deg + 1) % 360;
	mat4_rotatez(deg_to_rad((float)deg), model);

	uni_model = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, model);
}

void			show(const t_data *data)
{
	t_mat4	model;

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(data->window))
	{
		mat4_eq(model, data->model);

		glfwSwapBuffers(data->window);
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(data, model);

		/*
			glDrawArrays(GL_TRIANGLES,
				0,
				data->nfaces * N_VERTICES_PER_FACE);
		*/
		//
		glDrawElements(GL_TRIANGLES,
			data->nfaces * N_VERTICES_PER_FACE,
			GL_UNSIGNED_INT,
			(void *)(N_DATA_PER_VERTICE * 0));
		//
		usleep(25000);
	}

	glDisable(GL_DEPTH_TEST);
}
