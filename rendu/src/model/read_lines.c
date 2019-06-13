/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:35:18 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/13 10:35:19 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_lines.h"

static int	skip_line(FILE *fp)
{
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return (1);
	}
	return (1);
}

static int	check_type(const char *type, FILE *fp, t_model **model)
{
	const char		*str_tab[] = {"v", "f", "s", "mtllib", "usemtl"};
	int				(*const fn_tab[])(FILE *, t_model *) = {&read_v, &read_f,
		&read_s, &read_mtllib, &read_usemtl};
	unsigned int	i;

	i = 0;
	while (i < 5)
	{
		if (strcmp(type, str_tab[i]) == 0)
			return (fn_tab[i](fp, *model));
		i++;
	}
	if (i == 5)
		return (skip_line(fp));
	return (0);
}

void		read_lines(FILE *fp, t_model **model)
{
	char	type[21];
	int		ret;

	memset(type, '\0', 21);
	while (fscanf(fp, "%s", type) != EOF)
	{
		if (!type[0])
		{
			free_model(model);
			return ;
		}
		ret = check_type(type, fp, model);
		memset(type, '\0', 21);
		if (!ret)
		{
			free_model(model);
			return ;
		}
	}
}
