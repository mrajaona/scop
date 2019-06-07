#ifndef READ_MTL_H
# define READ_MTL_H

# include <string.h>

# include "model_struct.h"

void	open_mtl(const char *name, t_model *model);
void	use_mtl(const char *name, FILE *fp, t_material *material);

#endif