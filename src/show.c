#include "tuto.h"

/*
// dynamic color
uniColor = glGetUniformLocation(scop->shaderProgram, "triangleColor");
glUniform3f(uniColor, 1.0f, 0.0f, 0.0f);
*/

void	show(t_data *scop)
{
	while(!glfwWindowShouldClose(scop->window))
	{
		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}