#include "show.h"

void	show(const t_data *scop)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	while(!glfwWindowShouldClose(scop->window))
	{
		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}