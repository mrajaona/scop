/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:38:51 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:38:51 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_clr.h"

static void		clr_info(t_info *info)
{
	mat4_clr(info->mat_model);
	info->shader.program = 0;
	info->shader.vertex = 0;
	info->shader.fragment = 0;
	info->arrays.vao = 0;
	info->arrays.vbo = 0;
	info->nfaces = 0;
	clear_vector(info->center);
}

static void		clr_shadow(t_shadow *shadow)
{
	shadow->fbo = 0;
	shadow->map = 0;
	shadow->shader.program = 0;
	shadow->shader.vertex = 0;
	shadow->shader.fragment = 0;
	mat4_clr(shadow->mat_model);
	mat4_clr(shadow->mat_view);
	mat4_clr(shadow->mat_proj);
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
	clr_shadow(&(data->shadow));
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}
