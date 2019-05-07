#include "show.h"
#include <unistd.h> // debug

void	show(t_data *scop)
{
	while(!glfwWindowShouldClose(scop->window))
	{
		sleep(1); // debug
		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}