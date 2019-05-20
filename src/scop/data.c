#include "data.h"

static void	glerr(const char *s) // debug
{
	GLenum	err;

	err = glGetError();
	switch(err)
	{
		case GL_NO_ERROR :
			break ;
		case GL_INVALID_ENUM :
			fprintf(stderr, "%s : GL_INVALID_ENUM\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_VALUE :
			fprintf(stderr, "%s : GL_INVALID_VALUE\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_OPERATION :
			fprintf(stderr, "%s : GL_INVALID_OPERATION\n", s);
			fflush(stderr);
			break ;
		case GL_STACK_OVERFLOW :
			fprintf(stderr, "%s : GL_STACK_OVERFLOW\n", s);
			fflush(stderr);
			break ;
		case GL_STACK_UNDERFLOW :
			fprintf(stderr, "%s : GL_STACK_UNDERFLOW\n", s);
			fflush(stderr);
			break ;
		case GL_OUT_OF_MEMORY :
			fprintf(stderr, "%s : GL_OUT_OF_MEMORY\n", s);
			fflush(stderr);
			break ;
		case GL_INVALID_FRAMEBUFFER_OPERATION :
			fprintf(stderr, "%s : GL_INVALID_FRAMEBUFFER_OPERATION\n", s);
			fflush(stderr);
			break ;
		case GL_CONTEXT_LOST :
			fprintf(stderr, "%s : GL_CONTEXT_LOST\n", s);
			fflush(stderr);
			break ;
		case GL_TABLE_TOO_LARGE :
			fprintf(stderr, "%s : GL_TABLE_TOO_LARGE\n", s);
			fflush(stderr);
			break ;

	}
}

void	data_exit(t_data *data, const int status)
{
	data_del(data);
	exit(status);
}

void	data_del(t_data *data)
{
	shader_del(&(data->shader));
    glDeleteTextures(N_TEXTURES, data->textures);
	model_del(&(data->model));
	model_del(&(data->floor)); // tuto
	glfwTerminate();
}

void	data_clr(t_data *data)
{
	unsigned int	i;

	data->shader.program = 0;
	data->shader.vertex = 0;
	data->shader.fragment = 0;
	mat4_clr(data->view);
	mat4_clr(data->proj);
	model_clr(&(data->model));
	model_clr(&(data->floor)); // tuto
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}

void	data_init(t_data *data)
{
	data_clr(data);
	glerr("1");
	model_init(&(data->model));
	glerr("2");
	if (!shader_init(&(data->shader)))
		data_exit(data, 1);
	glerr("3");
	texture_init(data->textures, data->shader.program);
	glerr("4");
}