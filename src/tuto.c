#include "tuto.h"

static void	glew_init(GLuint *vertexBuffer)
{
	glewExperimental = GL_TRUE;
	int err;
	if ((err = glewInit()) != GLEW_OK)
	{
		write(2, "glew init error\n", 16); // err
		fprintf(stderr, "%s\n", glewGetErrorString(err));
		fflush(stderr);
		exit(1);
	}
	glGenBuffers(1, vertexBuffer);
}

static void	init(t_data *scop)
{
	glew_init(&(scop->vertexBuffer));
	vbo(&(scop->vbo));
	vao(&(scop->vao));
	ebo(&(scop->ebo));
	shader_program(&(scop->shaderProgram));
}

int			main()
{
	if (!glfwInit())
	{
		write(2, "glfw init error\n", 16); // err
		return (1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
	// GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

	if (!window) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");

		const char *description;
		int code = glfwGetError(&description);
		if (description)
			fprintf(stderr, "Code %i: %s\n", code, description);

		fflush(stderr);
		glfwTerminate();
		return (1);
	}

	glfwMakeContextCurrent(window);

	t_data	scop;
	init(&scop);

	show(window, &scop);

	glfwTerminate();
	return (0);
}
