#include "data.h"

void	data_exit(t_data *data, const int status)
{
	data_del(data);
	glfwTerminate();
	exit(status);
}

void	data_del(t_data *data)
{
	if (data->data)
		free(data->data);
	shader_del(&(data->shader));
    glDeleteTextures(N_TEXTURES, data->textures);
	model_del(&(data->model));
	model_del(&(data->floor)); // tuto
}

void	data_clr(t_data *data)
{
	unsigned int	i;

	data->data = NULL;
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
	if (!shader_init(&(data->shader)))
		data_exit(data, 1);
	texture_init(data->textures, data->shader.program);
}