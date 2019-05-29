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

static void		del_shader(t_shader *shader)
{
	if (shader->program)
		glDeleteProgram(shader->program);
	if (shader->fragment)
		glDeleteShader(shader->fragment);
	if (shader->vertex)
		glDeleteShader(shader->vertex);	
}

static void		del_arrays(t_arrays *arrays)
{
	if (arrays->vao)
		glDeleteVertexArrays(1, &(arrays->vao));
	if (arrays->vbo)
		glDeleteBuffers(1, &(arrays->vbo));
	if (arrays->ibo)
		glDeleteBuffers(1, &(arrays->ibo));
}

static void		data_del(t_data *data)
{
	del_shader(&(data->shader));
	
	glDeleteTextures(N_TEXTURES, data->textures);

	del_arrays(&(data->arrays_model));
	del_arrays(&(data->arrays_light));
	
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
