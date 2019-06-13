/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mtl_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:11:39 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:11:41 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_mtl_check.h"

int	check_vector(int *ret,
	const char *type, FILE *fp, t_material *material)
{
	const char *const	vector_str[] = {"Ka", "Kd", "Ks"};
	t_vector *const		vector_tab[] = {&(material->ka), &(material->kd),
		&(material->ks)};
	unsigned int		i;

	i = 0;
	while (i < 3)
	{
		if (strcmp(type, vector_str[i]) == 0)
		{
			*ret = fscanf(fp, "%f %f %f",
					&(((*vector_tab)[i])[0]),
					&(((*vector_tab)[i])[1]),
					&(((*vector_tab)[i])[2]))
				!= 3 ? 0 : 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_float(int *ret,
	const char *type, FILE *fp, t_material *material)
{
	const char *const	float_str[] = {"Ns", "Ni", "d", "Tr"};
	float *const		float_tab[] = {&(material->ns), &(material->ni),
		&(material->d), &(material->d)};
	unsigned int		i;

	i = 0;
	while (i < 4)
	{
		if (strcmp(type, float_str[i]) == 0)
		{
			*ret = fscanf(fp, "%f", float_tab[i]) != 1 ? 0 : 1;
			if (i == 3)
				material->d = 1 - material->d;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_illum(int *ret,
	const char *type, FILE *fp, t_material *material)
{
	if (strcmp(type, "illum") == 0)
	{
		*ret = fscanf(fp, "%i", &(material->illum)) != 1 ? 0 : 1;
		return (1);
	}
	return (0);
}
