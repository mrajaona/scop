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

/*
** plane[0] = near plane
** plane[1] = far plane
*/

# define NEAR_PLANE 0
# define FAR_PLANE 1

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest);

#endif
