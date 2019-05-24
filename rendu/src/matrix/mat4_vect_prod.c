/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vect_prod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:07 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:08 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4_vect_prod.h"

void		mat4_vector_prod(const t_mat4 lhs, const t_vector rhs, t_vector res)
{
	unsigned char	x;
	unsigned char	y;

	if (!lhs || !rhs || !res)
		return ;
	y = 0;
	while (y < 4)
	{
		x = 0;
		res[y] = 0;
		while (x < 4)
		{
			res[y] += mat4_get(lhs, x, y) * rhs[y];
			x++;
		}
		y++;
	}
}
