#ifndef VECTOR_OP_H
# define VECTOR_OP_H

# include <stdlib.h>
# include "vector.h"

t_vector_ptr	vector_add(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_sub(const t_vector lhs, const t_vector rhs,
	t_vector res);
t_vector_ptr	vector_scalar(const t_vector vec, const int scalar,
	t_vector res);

#endif
