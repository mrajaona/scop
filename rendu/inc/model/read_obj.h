#ifndef READ_OBJ_H
# define READ_OBJ_H

# include <stdio.h>

# include "glew_inc.h"

# include "model_struct.h"

int	read_v(FILE *fp, t_model *model);
int	read_f(FILE *fp, t_model *model);

#endif