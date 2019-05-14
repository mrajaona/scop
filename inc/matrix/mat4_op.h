#ifndef MATRIX_OP_H
# define MATRIX_OP_H

# include <stdlib.h>
# include "mat4.h"

t_mat4_ptr		mat4_add(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_sub(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_scalar(const t_mat4 mat, const int scalar, t_mat4 res);
t_mat4_ptr		mat4_mult(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);

#endif