#include "tuto.h"

static void	glew_init(GLuint *vertexBuffer)
{
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		write(2, "glew init error\n", 16); // err
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
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
	// GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

	glfwMakeContextCurrent(window);

	t_data	scop;
	init(&scop);

	show(window, &scop);

	glfwTerminate();
	return (0);
}
