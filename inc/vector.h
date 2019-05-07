#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>

typedef float	t_vector[4];
typedef float	*t_vector_ptr;

void			clear_vector(t_vector vec);
void			vector_eq(t_vector dst, t_vector src);
t_vector_ptr	vector_add(t_vector lhs, t_vector rhs, t_vector res);
t_vector_ptr	vector_sub(t_vector lhs, t_vector rhs, t_vector res);
t_vector_ptr	vector_scalar(t_vector vec, int scalar, t_vector res);

t_vector_ptr	vector_scalar_prod(t_vector lhs, t_vector rhs, t_vector res);
t_vector_ptr	vector_dot_prod(t_vector lhs, t_vector rhs, t_vector res);
void			normalize(t_vector vector, t_vector dest);

#endif