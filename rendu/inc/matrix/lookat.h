/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:28 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:28 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKAT_H
# define LOOKAT_H

# include <math.h>

# include "vector.h"
# include "vector_op.h"
# include "coord_op.h"
# include "mat4.h"

void	lookat(const t_vector eye, const t_vector target, const t_vector up,
	t_mat4 dest);

#endif
