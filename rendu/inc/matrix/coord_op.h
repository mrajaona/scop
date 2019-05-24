/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:17 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:20 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_OP_H
# define COORD_OP_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "coord.h"

t_coord_ptr	coord_cross_prod(const t_coord lhs, const t_coord rhs,
	t_coord res);
float		coord_dot_prod(const t_coord lhs, const t_coord rhs);
void		coord_normalize(const t_coord coord, t_coord dest);

#endif
