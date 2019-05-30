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

	static float	a = 0;
	t_vector		mov;
	coord_to_vec(-a, a, a, mov);
	translation(mov, model);
	a = a >= 3.0f ? -3.0f : (a + 0.05);

	deg = (deg - 1) % 360;
	// mat4_rotatey(deg_to_rad((float)deg), model);

	uni_model = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(uni_model, 1, GL_FALSE, model);
}

static void		show_model(const t_data *data)
{
	use_model(&(data->model));
	edit_output(data->model.shader.program, data->model.mat_model);
	glDrawArrays(GL_TRIANGLES, 0, data->nfaces * N_VERTICES_PER_FACE);
	use_no_model();
}

static void		show_light(const t_data *data)
{
	use_model(&(data->light));
	center(data->light.shader.program, data->light.mat_model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	use_no_model();
}

void			show(const t_data *data)
{
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(data->window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // background
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		show_model(data);
		show_light(data);

		usleep(25000);

		glfwSwapBuffers(data->window);
		glfwPollEvents();
	}

	glDisable(GL_DEPTH_TEST);
}
