#ifndef PROCESS_MODEL_H
# define PROCESS_MODEL_H

# include "glew_inc.h"
# include "glfw_inc.h"

# include "model_struct.h"
# include "data_struct.h"

# include "model.h"
# include "use_model.h"

/********************************************/

#include "vector.h"
#include "vector_op.h"
#include "coord.h"
#include "coord_op.h"

typedef struct	s_triangle
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_coord		normal;
}				t_triangle;

/********************************************/

int	process_model(const t_model *model, t_data *data);

#endif
