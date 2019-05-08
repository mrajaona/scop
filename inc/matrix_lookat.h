#ifndef MATRIX_LOOKAT_H
# define MATRIX_LOOKAT_H

# include <math.h>
# include "matrix.h"
# include "vector.h"

void	lookat(const t_vector eye, const t_vector target, const t_vector up,
	t_mat4 dest);

#endif
