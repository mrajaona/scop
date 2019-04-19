/*
#include <libraryheaders>

int main()
{
	createWindow(title, width, height);
	createOpenGLContext(settings);
	while (windowOpen)
	{
		while (event = newEvent())
			handleEvent(event);
		updateScene();
		drawGraphics();
		presentGraphics();
	}
	return (0);
}
*/
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	glfwTerminate();
}
