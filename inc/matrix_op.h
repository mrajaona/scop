#ifndef MATRIX_OP_H
# define MATRIX_OP_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

typedef	float	t_angle;

typedef struct	s_scale
{
	float	sx;
	float	sy;
	float	sz;
}				t_scale;

void			mat4_vector_prod(t_mat4 lhs, t_vector rhs, t_vector res);
void			translation(t_3d_coord *mov, t_mat4 dest);
void			scaling(t_scale *scale, t_mat4 dest);
float			deg_to_rad(float angle);
float			rad_to_deg(float angle);
void			rotatex(t_angle angle, t_mat4 dest);
void			rotatey(t_angle angle, t_mat4 dest);
void			rotatez(t_angle angle, t_mat4 dest);

#endif
