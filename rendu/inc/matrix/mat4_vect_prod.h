/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_vect_prod.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:22:19 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:22:20 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_VECT_PROD_H
# define MAT4_VECT_PROD_H

# include "mat4.h"
# include "vector.h"

void			mat4_vector_prod(const t_mat4 lhs, const t_vector rhs,
	t_vector res);

#endif
