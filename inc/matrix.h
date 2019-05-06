#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>

/*
** reading matrices :
** x goes right
** y goes down
*/

typedef double	t_mat4[16];
typedef double	*t_mat4_ptr;

void			mat4_set(t_mat4 mat, unsigned char x, unsigned char y,
	double value);
double			mat4_get(t_mat4 mat, unsigned char x, unsigned char y);

void			clear_matrix(t_mat4 mat);
void			identity(t_mat4 mat);

void			mat4_eq(t_mat4 dst, t_mat4 src);
t_mat4_ptr		mat4_add(t_mat4 lhs, t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_sub(t_mat4 lhs, t_mat4 rhs, t_mat4 res);
t_mat4_ptr		mat4_scalar(t_mat4 mat, int scalar, t_mat4 res);
t_mat4_ptr		mat4_mult(t_mat4 lhs, t_mat4 rhs, t_mat4 res);

#endif
