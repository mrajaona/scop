#ifndef MAT4_ROTATE_H
# define MAT4_ROTATE_H

# include <math.h>
# include "mat4.h"
# include "mat4_transform.h"

void	mat4_rotatex(const float angle, t_mat4 dest);
void	mat4_rotatey(const float angle, t_mat4 dest);
void	mat4_rotatez(const float angle, t_mat4 dest);

#endif
