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
#include <thread>

int main()
{
	glfwInit();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	glfwTerminate();
}
