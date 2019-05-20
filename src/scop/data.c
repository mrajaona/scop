#include "data.h"

void			data_del(t_data *data)
{
	if (data->shader.program)
		glDeleteProgram(data->shader.program);
	if (data->shader.fragment)
		glDeleteShader(data->shader.fragment);
	if (data->shader.vertex)
		glDeleteShader(data->shader.vertex);

    glDeleteTextures(N_TEXTURES, data->textures);

	glDeleteBuffers(1, &(data->model.ebo));
	glDeleteBuffers(1, &(data->model.vbo));
	glDeleteVertexArrays(1, &(data->model.vao));

	glfwTerminate();
}

void			data_exit(t_data *data, const int status)
{
	data_del(data);
	exit(status);
}

void			data_clr(t_data *data)
{
	unsigned int	i;

	data->shader.program = 0;
	data->shader.vertex = 0;
	data->shader.fragment = 0;

	mat4_clr(data->view);
	mat4_clr(data->proj);

	mat4_clr(data->model.mat);
	data->model.ebo = 0;
	data->model.vbo = 0;
	data->model.vao = 0;

	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}
