/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj_mtl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:47:02 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:47:03 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_obj_mtl.h"

int	read_mtllib(FILE *fp, t_model *model)
{
	char	name[21];
	int		rd;

	memset(name, '\0', 21);
	rd = fscanf(fp, "%s\n", name);
	if (!rd || !name[0])
		return (0);
	if ((model->mtl_fp))
	{
		fclose(model->mtl_fp);
		model->mtl_fp = 0;
	}
	open_mtl(name, model);
	if (!(model->mtl_fp))
		return (0);
	return (1);
}

int	read_usemtl(FILE *fp, t_model *model)
{
	char	name[21];
	int		rd;

	if (!fp)
		return (0);
	memset(name, '\0', 21);
	rd = fscanf(fp, "%20s\n", name);
	if (!rd || !name[0])
		return (0);
	use_mtl(name, model->mtl_fp, &(model->material));
	return (1);
}
