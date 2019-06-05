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
}

static void		del_depth(t_depth *depth)
{
	if (depth->fbo)
		glDeleteFramebuffers(1, &(depth->fbo));
	if (depth->shader.program)
		glDeleteProgram(depth->shader.program);
	if (depth->shader.fragment)
		glDeleteShader(depth->shader.fragment);
	if (depth->shader.vertex)
		glDeleteShader(depth->shader.vertex);	
}

static void		data_del(t_data *data)
{
	glDeleteTextures(N_TEXTURES, data->textures);
	del_info(&(data->model));
	del_depth(&(data->depth));
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
}

static void		clr_depth(t_depth *depth)
{
	depth->fbo = 0;
	depth->map = 0;
	depth->shader.program = 0;
	depth->shader.vertex = 0;
	depth->shader.fragment = 0;
	mat4_clr(depth->mat_model);
	mat4_clr(depth->mat_view);
	mat4_clr(depth->mat_proj);
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
	clr_depth(&(data->depth));
	data->nfaces = 0;
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}
