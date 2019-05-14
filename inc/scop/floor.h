#ifndef FLOOR_H
# define FLOOR_H

# include "data.h"
# include "mat4.h"
# include "mat4_op.h"
# include "mat4_transform.h"
# include "vector.h"
# include "coord.h"

void	set_floor(t_model *model);
void	draw_floor(const t_data *data, const t_mat4 edit);

#endif
