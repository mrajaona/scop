/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:21:45 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:21:46 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_OP_H
# define MAT4_OP_H

# include <stdlib.h>
# include "mat4.h"

t_mat4_ptr		mat4_add(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_sub(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_scalar(const t_mat4 mat, const int scalar, t_mat4 res);
t_mat4_ptr		mat4_mult(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);

#endif
