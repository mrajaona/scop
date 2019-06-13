/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:53:01 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:53:02 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_model.h"

char			*get_res_folder(const char *path)
{
	char	*tmp;
	char	*folder;

	folder = (char *)malloc(strlen(path) + 1);
	strcpy(folder, path);
	folder[strlen(path)] = '\0';
	tmp = strrchr(folder, '/');
	if (!tmp)
	{
		if ((folder = (char *)realloc(folder, 3)) != NULL)
			strcpy(folder, "./");
	}
	else
	{
		*(tmp + 1) = '\0';
		folder = (char *)realloc(folder, strlen(folder) + 1);
	}
	return (folder);
}

static t_model	*init_model(void)
{
	t_model	*model;

	if (!(model = (t_model *)malloc(sizeof(t_model))))
		return (NULL);
	model->vertices = NULL;
	model->faces = NULL;
	model->nfaces = 0;
	model->mtl_fp = NULL;
	model->material.ns = 32;
	coord_to_vec(1.0f, 1.0f, 1.0f, model->material.ka);
	coord_to_vec(1.0f, 1.0f, 1.0f, model->material.kd);
	coord_to_vec(1.0f, 1.0f, 1.0f, model->material.ks);
	model->material.ni = 1.0f;
	model->material.d = 1.0f;
	model->material.illum = 0;
	clear_vector(model->min);
	clear_vector(model->max);
	return (model);
}

static t_model	*read_failure(t_model **model)
{
	free_model(model);
	return (NULL);
}

t_model			*read_model(const char *path)
{
	t_model	*model;
	FILE	*fp;

	if (!(model = init_model()))
		return (NULL);
	if (!(model->res_folder = get_res_folder(path)))
		return (read_failure(&model));
	fp = fopen(path, "r");
	if (!fp)
	{
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (read_failure(&model));
	}
	read_lines(fp, &model);
	fclose(fp);
	if (model && (model->mtl_fp))
	{
		fclose(model->mtl_fp);
		model->mtl_fp = 0;
	}
	return (model);
}
