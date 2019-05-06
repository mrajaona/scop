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

#include "matrix_op.h"
#include "error.h"

int			main()
{
	t_data	scop;
	clr_scop(&scop);
	init(&scop);

	// debug
	t_mat4		trans;
	identity(trans);
	rotatez(deg_to_rad(180.0), trans);
	/*
	t_vector	ori;
	clear_vector(ori);
	ori[0] = 1;

	t_vector	res;
	mat4_vector_prod(trans, ori, res);

	fprintf(stdout, "x:%f y:%f z:%f w:%f\n", res[0], res[1], res[2], res[3]);
	fflush(stdout);
	*/
	GLint uniTrans = glGetUniformLocation(scop.shaderProgram, "trans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, trans);
	// end

	show(&scop);
	ft_exit(&scop, 0);
	// return (0);
}
