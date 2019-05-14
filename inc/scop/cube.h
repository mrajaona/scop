#ifndef CUBE_H
# define CUBE_H

# include "data.h"
# include "mat4.h"
# include "mat4_transform.h"
# include "vector.h"
# include "coord.h"

void	set_cube(t_model *model);
void	draw_cube(t_data *data);
void	draw_cube_reflection(t_data *data);

#endif
