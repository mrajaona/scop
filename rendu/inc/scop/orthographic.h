/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthographic.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:17 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 10:53:17 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORTHOGRAPHIC_H
# define ORTHOGRAPHIC_H

# include "mat4.h"

typedef struct	s_ortho
{
	float	left;
	float	right;
	float	bottom;
	float	top;
	float	near;
	float	far;
}				t_ortho;

void			orthographic(t_mat4 dest, t_ortho params);

#endif
