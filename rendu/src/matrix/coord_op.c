/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:19 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:32:19 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coord_op.h"

t_coord_ptr		coord_cross_prod(const t_coord lhs, const t_coord rhs,
	t_coord res)
{
	t_coord	tmp;

	if (!lhs || !rhs || !res)
		return (res);
	tmp[0] = (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
	tmp[1] = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
	tmp[2] = (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
	coord_eq(res, tmp);
	return (res);
}

float			coord_dot_prod(const t_coord lhs, const t_coord rhs)
{
	float	res;

	if (!lhs || !rhs)
		return (0);
	res = (lhs[0] * rhs[0])
		+ (lhs[1] * rhs[1])
		+ (lhs[2] * rhs[2]);
	return (res);
}

void			coord_normalize(const t_coord coord, t_coord dest)
{
	float		len;
	float		sqlen;
	t_coord		tmp;

	if (!coord || !dest)
		return ;
	sqlen = (coord[0] * coord[0])
		+ (coord[1] * coord[1])
		+ (coord[2] * coord[2]);
	len = sqrtf(sqlen);
	tmp[0] = sqlen ? (coord[0] / len) : 0;
	tmp[1] = sqlen ? (coord[1] / len) : 0;
	tmp[2] = sqlen ? (coord[2] / len) : 0;
	coord_eq(dest, tmp);
}
