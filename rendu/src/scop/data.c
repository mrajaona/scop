/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:54 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:55 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void		data_del(t_data *data)
{
	if (data->shader.program)
		glDeleteProgram(data->shader.program);
	if (data->shader.fragment)
		glDeleteShader(data->shader.fragment);
	if (data->shader.vertex)
		glDeleteShader(data->shader.vertex);
	glDeleteTextures(N_TEXTURES, data->textures);
	glDeleteVertexArrays(1, &(data->arrays_model.vao));
	glDeleteBuffers(1, &(data->arrays_model.vbo));
	glDeleteBuffers(1, &(data->arrays_model.ibo));
	glDeleteVertexArrays(1, &(data->arrays_light.vao));
	glDeleteBuffers(1, &(data->arrays_light.vbo));
	glDeleteBuffers(1, &(data->arrays_light.ibo));
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
	mat4_clr(data->model);
	data->arrays_model.vao = 0;
	data->arrays_model.vbo = 0;
	data->arrays_model.ibo = 0;
	data->arrays_light.vao = 0;
	data->arrays_light.vbo = 0;
	data->arrays_light.ibo = 0;
	data->nfaces = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}
