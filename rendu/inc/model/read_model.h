#ifndef READ_MODEL_H
# define READ_MODEL_H

# include <string.h>

# include "model.h"

# include "read_obj.h"
# include "read_mtl.h"

t_model		*read_model(const char *path);

#endif