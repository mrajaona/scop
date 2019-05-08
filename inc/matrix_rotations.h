#ifndef MATRIX_ROTATIONS_H
# define MATRIX_ROTATIONS_H

# include <math.h>
# include "matrix.h"
# include "vector.h"
# include "matrix_op.h"

float	deg_to_rad(const float angle);
float	rad_to_deg(const float angle);

void	rotatex(const float angle, t_mat4 dest);
void	rotatey(const float angle, t_mat4 dest);
void	rotatez(const float angle, t_mat4 dest);

#endif
