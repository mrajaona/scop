#ifndef MAT4_ROTATE_H
# define MAT4_ROTATE_H

# include <math.h>
# include "mat4.h"
# include "mat4_transform.h"

void	rotatex(const float angle, t_mat4 dest);
void	rotatey(const float angle, t_mat4 dest);
void	rotatez(const float angle, t_mat4 dest);

#endif
