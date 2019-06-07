/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:37 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:38 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# include <stdio.h>

/*
** reading matrices :
** x goes right
** y goes down
*/

typedef float	t_mat4[16];
typedef float	*t_mat4_ptr;

void			mat4_set(t_mat4 mat,
	const unsigned char x, const unsigned char y,
	const float value);
float			mat4_get(const t_mat4 mat,
	const unsigned char x, const unsigned char y);

void			mat4_clr(t_mat4 mat);
void			identity(t_mat4 mat);

void			mat4_eq(t_mat4 dst, const t_mat4 src);

#endif
