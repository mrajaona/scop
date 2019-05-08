#ifndef MATRIX_OP_H
# define MATRIX_OP_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

void			coord_to_vec(const float x, const float y, const float z,
	t_vector dest);
void			mat4_vector_prod(const t_mat4 lhs, const t_vector rhs,
	t_vector res);
void			transform(const t_mat4 trans, t_mat4 dest);
void			translation(const t_vector mov, t_mat4 dest);
void			scaling(const t_vector scale, t_mat4 dest);

#endif
