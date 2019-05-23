#ifndef COORD_OP_H
# define COORD_OP_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "coord.h"

t_coord_ptr	coord_cross_prod(const t_coord lhs, const t_coord rhs,
	t_coord res);
float       coord_dot_prod(const t_coord lhs, const t_coord rhs);
void		coord_normalize(const t_coord, t_coord dest);

#endif