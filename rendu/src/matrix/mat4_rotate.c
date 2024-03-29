/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:51 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:32:52 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4_rotate.h"

/*
** 1 0  0 0
** 0 c -s 0
** 0 s  c 0
** 0 0  0 1
*/

void	mat4_rotatex(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
	mat4_set(rotate_mat, 1, 1, c);
	mat4_set(rotate_mat, 2, 1, -1 * s);
	mat4_set(rotate_mat, 1, 2, s);
	mat4_set(rotate_mat, 2, 2, c);
	transform(rotate_mat, dest);
}

/*
**  c 0 s 0
**  0 1 0 0
** -s 0 c 0
**  0 0 0 1
*/

void	mat4_rotatey(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 2, 0, s);
	mat4_set(rotate_mat, 0, 2, -1 * s);
	mat4_set(rotate_mat, 2, 2, c);
	transform(rotate_mat, dest);
}

/*
** c -s 0 0
** s  c 0 0
** 0  0 1 0
** 0  0 0 1
*/

void	mat4_rotatez(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 1, 0, -1 * s);
	mat4_set(rotate_mat, 0, 1, s);
	mat4_set(rotate_mat, 1, 1, c);
	transform(rotate_mat, dest);
}
