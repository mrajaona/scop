#ifndef OBJ_H
# define OBJ_H

# include "data.h"
# include "mat4.h"
# include "mat4_op.h"
# include "mat4_transform.h"
# include "vector.h"
# include "coord.h"

void	init_obj(t_model *model);
void	draw_cube(const t_data *data, const t_mat4 edit);
void	draw_floor(const t_data *data, const t_mat4 edit);
void	draw_cube_reflection(const t_data *data, const t_mat4 edit);

#endif
