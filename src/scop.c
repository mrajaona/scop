#include "scop.h"

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
	shader_program(&(scop->shaderProgram), scop);
	tex(scop->textures, scop);
}

static void	clr_scop(t_data *scop)
{
	unsigned int i;

	scop->window = NULL;
	scop->vertexBuffer = 0;
	scop->vbo = 0;
	scop->vao = 0;
	scop->ebo = 0;	
	scop->vertexShader = 0;
	scop->fragmentShader = 0;
	scop->shaderProgram = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		scop->textures[i] = 0;
		i++;
	}
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