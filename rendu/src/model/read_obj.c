/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:53:15 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:53:16 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_obj.h"

static void	min_max(t_model *model, float *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!model->min[i] && !model->max[i])
		{
			model->min[i] = data[i];
			model->max[i] = data[i];
		}
		else
		{
			if (data[i] < model->min[i])
				model->min[i] = data[i];
			if (data[i] > model->max[i])
				model->max[i] = data[i];
		}
		i++;
	}
}

/*
** leaks sur la liste de vertices
** TODO : implémenter std::vector
** ou utiliser un simple tableau avec realloc
*/

int			read_v(FILE *fp, t_model *model)
{
	t_list				*current;
	float				*tmp;
	static unsigned int	index = 0;
	char				c;

	if (!(current = new_elem(&(model->vertices), 3 * sizeof(float))))
		return (0);
	tmp = (float *)(current->data);
	if (fscanf(fp, "%f %f %f%c",
			&(tmp[0]),
			&(tmp[1]),
			&(tmp[2]),
			&c)
		!= 4 || c != '\n')
		return (0);
	min_max(model, tmp);
	current->index = index;
	index++;
	return (1);
}

static int	read_f_elem(int rd, GLuint face[4], t_model *model)
{
	t_list	*current;
	GLuint	*tmp;

	if (!(current = new_elem(&(model->faces), 3 * sizeof(GLuint))))
		return (0);
	model->nfaces++;
	tmp = (GLuint *)(current->data);
	tmp[0] = face[0] - 1;
	tmp[1] = face[1] - 1;
	tmp[2] = face[2] - 1;
	if (rd == 4)
	{
		if (!(current = new_elem(&(model->faces), 3 * sizeof(GLuint))))
			return (0);
		model->nfaces++;
		tmp = (GLuint *)(current->data);
		tmp[0] = face[2] - 1;
		tmp[1] = face[3] - 1;
		tmp[2] = face[0] - 1;
	}
	return (1);
}

int			read_f(FILE *fp, t_model *model)
{
	int		rd;
	GLuint	face[4];
	char	c;

	rd = fscanf(fp, "%u %u %u%c%u%c",
		&(face[0]),
		&(face[1]),
		&(face[2]),
		&c,
		&(face[3]),
		&c);
	if ((rd != 4 && rd != 6)
		|| c != '\n'
		|| face[0] == 0
		|| face[1] == 0
		|| face[2] == 0
		|| (rd == 5 && face[3] == 0))
		return (0);
	if (rd == 6 || rd == 4)
		return (read_f_elem(rd == 6 ? 4 : 3, face, model));
	return (0);
}

/*
** off = 0
** (not supported)
*/

int			read_s(FILE *fp, t_model *model)
{
	char	c;

	fscanf(fp, "%*s%c", &c);
	(void)model;
	if (c != '\n')
		return (0);
	return (1);
}
