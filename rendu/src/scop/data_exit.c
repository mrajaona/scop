/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:54 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:55 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_exit.h"

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

static void		del_shadow(t_shadow *shadow)
{
	if (shadow->fbo)
		glDeleteFramebuffers(1, &(shadow->fbo));
	if (shadow->shader.program)
		glDeleteProgram(shadow->shader.program);
	if (shadow->shader.fragment)
		glDeleteShader(shadow->shader.fragment);
	if (shadow->shader.vertex)
		glDeleteShader(shadow->shader.vertex);
}

static void		data_del(t_data *data)
{
	glDeleteTextures(N_TEXTURES, data->textures);
	del_info(&(data->model));
	del_shadow(&(data->shadow));
	glfwTerminate();
}

void			data_exit(t_data *data, const int status)
{
	data_del(data);
	exit(status);
}
