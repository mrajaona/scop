/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:09 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:10 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "vector.h"

typedef float	t_coord[3];
typedef float	*t_coord_ptr;

void			coord_print(const t_coord src);
void			clear_coord(t_coord coord);
void			coord_eq(t_coord dst, const t_coord src);

void			coord_to_vec(const float x, const float y, const float z,
	t_vector dest);

#endif
