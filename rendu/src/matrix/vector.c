/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:21 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:21 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// debug

void	vector_print(const t_vector vec)
{
	if (!vec)
		return ;
	fprintf(stdout, "\n% .2f\n% .2f\n% .2f\n% .2f\n",
		vec[0], vec[1], vec[2], vec[3]);
	fflush(stdout);
}

/*
** 0
** 0
** 0
** 1
*/

void	clear_vector(t_vector vec)
{
	if (!vec)
		return ;
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 0;
	vec[3] = 1;
}

void	vector_eq(t_vector dst, const t_vector src)
{
	unsigned char	y;

	if (!dst || !src)
		return ;
	y = 0;
	while (y < 4)
	{
		dst[y] = src[y];
		y++;
	}
}
