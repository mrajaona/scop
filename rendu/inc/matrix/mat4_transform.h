/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:22:06 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:22:06 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_TRANSFORM_H
# define MAT4_TRANSFORM_H

# include "mat4.h"
# include "mat4_op.h"
# include "vector.h"

void			transform(const t_mat4 trans, t_mat4 dest);
void			translation(const t_vector mov, t_mat4 dest);
void			scaling(const t_vector scale, t_mat4 dest);

#endif
