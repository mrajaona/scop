#include "show.h"

static void	edit_output(t_mat4 edit)
{
	static int		deg = 0;

	deg = (deg + 1) % 360;
	mat4_rotatez(deg_to_rad((float)deg), edit);
}

#include <unistd.h> // sleep
void	show(const t_data *data)
{
	t_mat4	edit;

	identity(edit);

	glEnable(GL_DEPTH_TEST);

	GLint uniColor = glGetUniformLocation(data->shader.program, "overrideColor");
	glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	// !window

	while(!glfwWindowShouldClose(data->window))
	{
		glfwSwapBuffers(data->window);
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(edit);

		draw_cube(data, edit);
		draw_floor(data, edit);
		draw_cube_reflection(data, edit);

		usleep(25000);
	}

	glDisable(GL_DEPTH_TEST);
}