#ifndef MATRIX_OP_H
# define MATRIX_OP_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

typedef struct	s_scale
{
	float	sx;
	float	sy;
	float	sz;
}				t_scale;

void			coord_to_vec(const float x, const float y, const float z,
	t_vector dest);
void			mat4_vector_prod(const t_mat4 lhs, const t_vector rhs,
	t_vector res);
void			transform(const t_mat4 trans, t_mat4 dest);
void			translation(const t_vector mov, t_mat4 dest);
void			scaling(const t_scale *scale, t_mat4 dest);
float			deg_to_rad(const float angle);
float			rad_to_deg(const float angle);
void			rotatex(const float angle, t_mat4 dest);
void			rotatey(const float angle, t_mat4 dest);
void			rotatez(const float angle, t_mat4 dest);

#endif
