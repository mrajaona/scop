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

static void		center(const GLuint program, const t_mat4 src)
{
	GLint		uni_model;
	t_mat4		model;

	if (src)
		mat4_eq(model, src);
	else
		identity(model);

	uni_model = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, model);
}

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

/*static*/ void		show_model(const t_data *data)
{
	edit_output(data->model.shader.program, data->mat_model);

	glBindVertexArray(data->model.arrays.vao);
	glUseProgram(data->model.shader.program);
	glDrawElements(GL_TRIANGLES,
		data->nfaces * N_VERTICES_PER_FACE,
		GL_UNSIGNED_INT,
		(void *)(N_DATA_PER_VERTICE * 0));
	glBindVertexArray(0);
}

/*static*/ void		show_light(const t_data *data)
{
	center(data->light.shader.program, NULL);

	glBindVertexArray(data->light.arrays.vao);
	glUseProgram(data->light.shader.program);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void			show(const t_data *data)
{
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(data->window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// show_light(data);
		show_model(data);

		usleep(25000);

		glfwSwapBuffers(data->window);
		glfwPollEvents();
	}

	glDisable(GL_DEPTH_TEST);
}
