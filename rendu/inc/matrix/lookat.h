#ifndef LOOKAT_H
# define LOOKAT_H

# include <math.h>

# include "vector.h"
# include "vector_op.h"
# include "coord_op.h"
# include "mat4.h"

void	lookat(const t_vector eye, const t_vector target, const t_vector up,
	t_mat4 dest);

#endif
