#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef float	t_vector[4];
typedef float	*t_vector_ptr;

void			vector_print(const t_vector src);

void			clear_vector(t_vector vec);
void			vector_eq(t_vector dst, const t_vector src);
t_vector_ptr	vector_add(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_sub(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_scalar(const t_vector vec, const int scalar,
	t_vector res);

t_vector_ptr	coord_cross_prod(const t_vector lhs, const t_vector rhs, t_vector res);
float       	coord_dot_prod(const t_vector lhs, const t_vector rhs);
void			coord_normalize(const t_vector vector, t_vector dest);

#endif
