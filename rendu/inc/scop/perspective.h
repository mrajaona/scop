/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:24:29 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:24:29 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSPECTIVE_H
# define PERSPECTIVE_H

# include <math.h>
# include "mat4.h"
# include "angle.h"

/*
** plane[0] = near plane
** plane[1] = far plane
*/

# define P_NEAR 0.001f
# define P_FAR 100.0f
# define VFOV_DEG 80.0f
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define SCREEN_RATIO ((float)SCREEN_WIDTH / (float)SCREEN_HEIGHT)

void	perspective(t_mat4 dest);

#endif
