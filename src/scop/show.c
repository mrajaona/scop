#include "show.h"

static void	edit_output(const t_data *data, t_mat4 model)
{
	static int		deg = 0;

	deg = (deg + 1) % 360;
	mat4_rotatez(deg_to_rad((float)deg), model);

	GLint uniModel = glGetUniformLocation(data->shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);
}

#include <unistd.h> // sleep
void	show(const t_data *data)
{
	t_mat4	model;

	glEnable(GL_DEPTH_TEST);

	GLint uniColor = glGetUniformLocation(data->shaderProgram, "overrideColor");
	glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	while(!glfwWindowShouldClose(data->window))
	{
		mat4_eq(model, data->model);

		glfwSwapBuffers(data->window);
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(data, model);

		draw_cube();
		draw_floor();
		draw_reflection();

		usleep(25000);
	}

	glDisable(GL_DEPTH_TEST);
}