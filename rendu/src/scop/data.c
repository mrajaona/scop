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

static void		del_info(t_info *info)
{
	if (info->shader.program)
		glDeleteProgram(info->shader.program);
	if (info->shader.fragment)
		glDeleteShader(info->shader.fragment);
	if (info->shader.vertex)
		glDeleteShader(info->shader.vertex);	
	if (info->arrays.vao)
		glDeleteVertexArrays(1, &(info->arrays.vao));
	if (info->arrays.vbo)
		glDeleteBuffers(1, &(info->arrays.vbo));
	if (info->arrays.fbo)
		glDeleteFramebuffers(1, &(info->arrays.fbo));
}

static void		data_del(t_data *data)
{
	glDeleteTextures(N_TEXTURES, data->textures);
	del_info(&(data->model));
	glfwTerminate();
}

void			data_exit(t_data *data, const int status)
{
	data_del(data);
	exit(status);
}

static void		clr_info(t_info *info)
{
	mat4_clr(info->mat_model);
	info->shader.program = 0;
	info->shader.vertex = 0;
	info->shader.fragment = 0;
	info->arrays.vao = 0;
	info->arrays.vbo = 0;
	info->arrays.fbo = 0;
}

static void		clr_light(t_light *light)
{
	clear_vector(light->position);
	clear_vector(light->color);
	clear_vector(light->ambient);
	clear_vector(light->diffuse);
	clear_vector(light->specular);
}

void			data_clr(t_data *data)
{
	unsigned int	i;

	mat4_clr(data->mat_view);
	mat4_clr(data->mat_proj);
	clr_info(&(data->model));
	clr_light(&(data->light));
	data->nfaces = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
	data->depth_map = 0;
}
