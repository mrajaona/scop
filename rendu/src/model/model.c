/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:40 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:41 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"

void		free_model(t_model **model)
{
	if (!model || !(*model))
		return ;
	free_list(&((*model)->vertices));
	free_list(&((*model)->faces));
	if ((*model)->mtl_fp)
	{
		fclose((*model)->mtl_fp);
		(*model)->mtl_fp = NULL;
	}
	free(*model);
	*model = NULL;
}

/*
** #		- comments, which are ignored
** mtllib	- the filename of a materials definition file
** o		- gives the name of a model.
** -			All data between this type and the next o type is a single model.
** v		- defines the x, y, and z value of a single vertex
** usemtl	- use a specific color and material definition for the following polygons.
** s		- turn smooth shading off or on; flat shading is used when smooth shading is off.
** f		- defines the vertices that compose a face. Note that faces can have more than 3 vertices.
** -			In this example the faces have four vertices which define quad polygons.
** -			These must be divided into triangles before WebGL rendering.
*/

int				load_model(const char *path, t_data *data)
{
	t_model	*model;

	if (!(model = read_model(path)))
		return (0);
	else
	{
		fprintf(stdout, "model read\n");
		fflush(stdout);
	}
	if (!(process_model(model, data)))
		return (0);
	else
	{
		fprintf(stdout, "model processed\n");
		fflush(stdout);
	}
	free_model(&model);
	return (1);
}
