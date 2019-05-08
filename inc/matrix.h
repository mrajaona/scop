#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>

/*
** reading matrices :
** x goes right
** y goes down
*/

typedef float	t_mat4[16];
typedef float	*t_mat4_ptr;

void			mat4_set(t_mat4 mat,
	const unsigned char x, const unsigned char y,
	const float value);
float			mat4_get(const t_mat4 mat,
	const unsigned char x, const unsigned char y);

void			clear_matrix(t_mat4 mat);
void			identity(t_mat4 mat);

void			mat4_eq(t_mat4 dst, const t_mat4 src);
t_mat4_ptr		mat4_add(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_sub(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_scalar(const t_mat4 mat, const int scalar, t_mat4 res);
t_mat4_ptr		mat4_mult(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res);

#endif
