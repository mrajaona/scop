#include "tuto.h"

void	ft_exit(t_data *scop, int status)
{
	glDeleteTextures(1, &(scop->tex));

    glDeleteProgram(scop->shaderProgram);
    glDeleteShader(scop->fragmentShader);
    glDeleteShader(scop->vertexShader);

    glDeleteBuffers(1, &(scop->ebo));
    glDeleteBuffers(1, &(scop->vbo));

    glDeleteVertexArrays(1, &(scop->vao));

	glfwTerminate();
	exit(status);
}

// GLEW
static void	glew_init(GLuint *vertexBuffer)
{
	glewExperimental = GL_TRUE;
	int err;
	if ((err = glewInit()) != GLEW_OK)
	{
		fprintf(stderr, "glew init error\n%s\n", glewGetErrorString(err));
		fflush(stderr);
		exit(1);
	}
	glGenBuffers(1, vertexBuffer);
}

static void	init(t_data *scop)
{
	glfw_init(&(scop->window));
	glew_init(&(scop->vertexBuffer));
	vbo(&(scop->vbo));
	vao(&(scop->vao));
	ebo(&(scop->ebo));
	tex(&(scop->tex), scop);
	shader_program(&(scop->shaderProgram), scop);
}

static void	clr_scop(t_data *scop)
{
	scop->window = NULL;
	scop->vertexBuffer = 0;
	scop->vbo = 0;
	scop->vao = 0;
	scop->ebo = 0;	
	scop->vertexShader = 0;
	scop->fragmentShader = 0;
	scop->shaderProgram = 0;
	// scop->uniColor = 0;
	scop->tex = 0;
}

int			main()
{
	t_data	scop;
	clr_scop(&scop);
	init(&scop);
	show(&scop);
	ft_exit(&scop, 0);
	// return (0);
}
