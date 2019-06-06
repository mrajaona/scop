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

static void		edit_output(const GLuint program, const t_mat4 src)
{
	static int	deg = 0;
	t_mat4		model;
	GLint		uni_model;

	if (src)
		mat4_eq(model, src);
	else
		identity(model);

	deg = (deg - 1) % 360;
	mat4_rotatey(deg_to_rad((float)deg), model);

	uni_model = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, model);
}

static void		show_model(const t_data *data)
{
	glBindTexture(GL_TEXTURE_2D, data->textures[0]);

	use_model(&(data->model));
	edit_output(data->model.shader.program, data->model.mat_model);
	glDrawArrays(GL_TRIANGLES, 0, data->model.nfaces * N_VERTICES_PER_FACE);
	use_no_model();
}

void			show(const t_data *data)
{
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(data->window))
	{
		glClearColor(0.5f, 0.5f, 0.5f, 0.5f); // background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		show_model(data);

		usleep(25000);

		glfwSwapBuffers(data->window);
		glfwPollEvents();
	}

	glDisable(GL_DEPTH_TEST);
}
