#ifndef SET_DATA_H
# define SET_DATA_H

# include "glew_inc.h"

# include "data_struct.h"

# include "vector.h"
# include "coord.h"

# include "lookat.h"
# include "perspective.h"

# include "angle.h"

void 			set_model(t_data *data);
void			set_view(t_data *data);
void			set_proj(t_data *data);

#endif
