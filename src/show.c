#include "tuto.h"

/*
static void	color_loop(t_data *scop)
{
	static double lol = 1;

	lol -= 0.00001;
	glUniform3f(scop->uniColor, lol, lol, lol);
}
*/

void	show(t_data *scop)
{
	/*
	// triangle color
	scop->uniColor = glGetUniformLocation(scop->shaderProgram, "triangleColor");
	glUniform3f(scop->uniColor, 1.0f, 0.0f, 0.0f);
	*/

	while(!glfwWindowShouldClose(scop->window))
	{
		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// color_loop(scop);
	}
}