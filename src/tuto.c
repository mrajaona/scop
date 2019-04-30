#include "tuto.h"

static void	glew_init()
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		write(2, "glew init error\n", 16); // err
	}
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
}

static void	init()
{
	glew_init();
	vbo();
	vao();
	shader_program();
}

int			main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
	// GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

	glfwMakeContextCurrent(window);

	init();

	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	glfwTerminate();
	return (0);
}
