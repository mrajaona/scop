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

#include <unistd.h>
void	show(const t_data *scop)
{

	while(!glfwWindowShouldClose(scop->window))
	{
		sleep(1);
		edit_output(scop);

		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}