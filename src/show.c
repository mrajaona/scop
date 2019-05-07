#include "show.h"
#include <unistd.h> // debug

void	show(t_data *scop)
{
	while(!glfwWindowShouldClose(scop->window))
	{
		glfwSwapBuffers(scop->window);
		glfwPollEvents();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        sleep(1); // debug
	}
}