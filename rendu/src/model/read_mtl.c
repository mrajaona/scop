/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mtl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:53:07 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:53:08 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_mtl.h"

static void	skip_line(FILE *fp)
{
	char	s[1025];

	if (!fp)
		return ;
	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return ;
	}
}

static int	find_mtl(const char *name, FILE *fp)
{
	char				type[21];
	char				material[21];

	if (!fp)
		return (0);
	memset(type, '\0', 11);
	while (fscanf(fp, "%20s", type) != EOF)
	{
		if (!type[0])
			return (0);
		if (strcmp(type, "newmtl") == 0)
		{
			if (!fscanf(fp, "%20s", material))
				return (0);
			else if (strcmp(material, name) == 0)
			{
				skip_line(fp);
				return (1);
			}
		}
		skip_line(fp);
		memset(type, '\0', 21);
	}
	return (0);
}

void		use_mtl(const char *name, FILE *fp, t_material *material)
{
	char				type[21];
	int					ret;

	if (!fp)
		return ;
	fseek(fp, 0, SEEK_SET);
	if (!find_mtl(name, fp))
		return ;
	memset(type, '\0', 11);
	while (fscanf(fp, "%20s", type) != EOF)
	{
		if (!type[0])
			return ;
		if (strcmp(type, "newmtl") == 0)
			return ;
		if (!check_vector(&ret, type, fp, material))
			if (!check_float(&ret, type, fp, material))
				check_illum(&ret, type, fp, material);
		if (!ret)
			return ;
		skip_line(fp);
		memset(type, '\0', 21);
	}
}

void		open_mtl(const char *name, t_model *model)
{
	char	*path;
	size_t	len;

	len = strlen(model->res_folder) + strlen(name) + 1;
	if ((path = (char *)malloc(len)) == NULL)
		return ;
	memset(path, '\0', len);
	strcat(path, model->res_folder);
	strcat(path, name);
	model->mtl_fp = fopen(path, "r");
	free(path);
}
