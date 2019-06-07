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

int			g_blend_factor = -1;
t_vector	g_move = {0, 0, 0, 1};

static void		glfw_callback(GLFWwindow *window, int key, int scancode,
	int action, int mods)
{
	(void)window;
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		g_blend_factor *= -1;
	if (key == GLFW_KEY_UP
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[2] -= MV_VALUE;
	if (key == GLFW_KEY_DOWN
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[2] += MV_VALUE;
	if (key == GLFW_KEY_LEFT
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[0] -= MV_VALUE;
	if (key == GLFW_KEY_RIGHT
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[0] += MV_VALUE;
	if (key == GLFW_KEY_PAGE_UP
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[1] += MV_VALUE;
	if (key == GLFW_KEY_PAGE_DOWN
		&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		g_move[1] -= MV_VALUE;
}

static void		edit_output(const GLuint program, const t_info *src)
{
	static int		deg = 0;
	static float	blend = 0.0f;
	t_mat4		model;
	t_vector	to_center;
	t_vector	to_origin;
	GLint		uniform;

	mat4_eq(model, src->mat_model);
	vector_eq(to_origin, src->center);

	vector_scalar(to_origin, -1, to_center);
	translation(to_center, model);

	deg = (deg - 1) % 360;
	mat4_rotatey(deg_to_rad((float)deg), model);

	translation(to_origin, model);

	translation(g_move, model);

	uniform = glGetUniformLocation(program, "model");
	glUniformMatrix4fv(uniform, 1, GL_FALSE, model);

	uniform = glGetUniformLocation(program, "blend");
	glUniform1f(uniform, blend);

	blend += 0.01f * g_blend_factor;

	if (blend > 1.0f)
		blend = 1.0f;
	else if (blend < 0.0f)
		blend = 0.0f;
}

static void		show_model(const t_data *data)
{
	glBindTexture(GL_TEXTURE_2D, data->textures[0]);

	use_model(&(data->model));
	edit_output(data->model.shader.program, &(data->model));
	glDrawArrays(GL_TRIANGLES, 0, data->model.nfaces * N_VERTICES_PER_FACE);
	use_no_model();
}

void			show(const t_data *data)
{
	glfwSetKeyCallback(data->window, &glfw_callback);

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
