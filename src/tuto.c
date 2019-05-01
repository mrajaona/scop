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
	shader_program(&(scop->shaderProgram));
}

/*
static void	color_loop(t_data *scop)
{
	static double lol = 1;

	lol -= 0.00001;
	glUniform3f(scop->uniColor, lol, lol, lol);
}
*/

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

	t_data	scop;
	init(&scop);

	/*
	// triangle color
	scop.uniColor = glGetUniformLocation(scop.shaderProgram, "triangleColor");
	glUniform3f(scop.uniColor, 1.0f, 0.0f, 0.0f);
	*/

	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		// color_loop(&scop);
	}

	glfwTerminate();
	return (0);
}
