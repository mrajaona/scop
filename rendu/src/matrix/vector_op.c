/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:29 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:30 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_op.h"

t_vector_ptr	vector_add(const t_vector lhs, const t_vector rhs, t_vector res)
{
	unsigned char	y;
	t_vector		tmp;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		tmp[y] = lhs[y] + rhs[y];
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}

t_vector_ptr	vector_sub(const t_vector lhs, const t_vector rhs, t_vector res)
{
	unsigned char	y;
	t_vector		tmp;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		tmp[y] = lhs[y] - rhs[y];
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}

t_vector_ptr	vector_scalar(const t_vector vec, const int scalar,
	t_vector res)
{
	unsigned char	y;
	t_vector		tmp;

	if (!vec || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		tmp[y] = vec[y] * scalar;
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}
