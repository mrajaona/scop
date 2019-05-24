#include "init_ext.h"

void			glfw_init(GLFWwindow **window)
{
	if (!glfwInit())
	{
		fprintf(stderr, "glfw init error\n");
		fflush(stderr);
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	*window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
	// window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

	if (!(*window))
	{
		const char *description;
		int code;

		code = glfwGetError(&description);
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		if (description)
			fprintf(stderr, "Code %i: %s\n", code, description);
		fflush(stderr);
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(*window);	
}

/*
void			glew_init(void)
{
	glewExperimental = GL_TRUE;
	int err;
	if ((err = glewInit()) != GLEW_OK)
	{
		fprintf(stderr, "glew init error\n%s\n", glewGetErrorString(err));
		fflush(stderr);
		exit(1);
	}
}
*/