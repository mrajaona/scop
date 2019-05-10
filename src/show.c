#include "show.h"

static void	edit_output(const t_data *scop, t_mat4 model)
{
	static int		deg = 0;

	deg = (deg + 10) % 360;
	rotatez(deg_to_rad((float)deg), model);

	GLint uniModel = glGetUniformLocation(scop->shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);
}

static void	stencil(const t_data *scop, t_mat4 model)
{
	GLint uniColor = glGetUniformLocation(scop->shaderProgram, "overrideColor");
	glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	// Draw cube
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glEnable(GL_STENCIL_TEST);

	// Draw floor
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF);
	glDepthMask(GL_FALSE);
	glClear(GL_STENCIL_BUFFER_BIT);
	
	glDrawArrays(GL_TRIANGLES, 36, 6);

	// Draw reflection

	glStencilFunc(GL_EQUAL, 1, 0xFF);
	glStencilMask(0x00);
	glDepthMask(GL_TRUE);

	t_vector	edit;

	coord_to_vec(1.0f, 1.0f, -1.0f, edit);
	scaling(edit, model);

	coord_to_vec(0.0f, 0.0f, -1.0f, edit);
	translation(edit, model);

	GLint uniModel = glGetUniformLocation(scop->shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	glDisable(GL_STENCIL_TEST);
}

#include <unistd.h> // sleep
void	show(const t_data *scop)
{
	t_mat4	model;

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);

	while(!glfwWindowShouldClose(scop->window))
	{
		mat4_eq(model, scop->model);

		glfwSwapBuffers(scop->window);
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(scop, model);

		stencil(scop, model);

		sleep(1);
	}

	glDisable(GL_DEPTH_TEST);
}