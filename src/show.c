#include "show.h"

static void	edit_output(const t_data *scop)
{
	t_mat4			model;
	static int		deg = 0;

	identity(model);
	deg = (deg + 10) % 360;
	rotatez(deg_to_rad((float)deg), model);

    GLint uniTrans = glGetUniformLocation(scop->shaderProgram, "model");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, model);
}

static void	stencil(const t_data *scop)
{
	(void)scop;

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
	/*
	t_vector	edit;
	t_mat4		model;

	identity(model);

	coord_to_vec(0.0f, 0.0f, -1.0f, edit);
	translation(edit, model);

	coord_to_vec(1.0f, 1.0f, -1.0f, edit);

	scaling(edit, model);

	GLint uniModel = glGetUniformLocation(scop->shaderProgram, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	// glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    // glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	*/

	glDisable(GL_STENCIL_TEST);
}

#include <unistd.h>
void	show(const t_data *scop)
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_STENCIL_TEST);

	while(!glfwWindowShouldClose(scop->window))
	{
		glfwSwapBuffers(scop->window);
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(scop);

		stencil(scop);

		sleep(1);
	}

	glDisable(GL_DEPTH_TEST);
}