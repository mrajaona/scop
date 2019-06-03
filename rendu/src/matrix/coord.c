/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:14 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:32:14 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"

void	coord_print(const t_coord vec)
{
	if (!vec)
		return ;
	fprintf(stdout, "\n% .2f % .2f % .2f\n",
		vec[0], vec[1], vec[2]);
	fflush(stdout);
}

/*
** 0
** 0
** 0
** 1
*/

void	clear_coord(t_coord coord)
{
	if (!coord)
		return ;
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
}

void	coord_eq(t_coord dst, const t_coord src)
{
	unsigned char	y;

	if (!dst || !src)
		return ;
	y = 0;
	while (y < 3)
	{
		dst[y] = src[y];
		y++;
	}
}

void	coord_to_vec(const float x, const float y, const float z,
	t_vector dest)
{
	if (!dest)
		return ;
	dest[0] = x;
	dest[1] = y;
	dest[2] = z;
	dest[3] = 1;
}
