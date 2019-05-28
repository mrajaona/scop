#include "read_mtl.h"

void	open_mtl(char *name, t_model *model)
{
	char	*path;
	size_t	len;

	len = strlen(model->res_folder) + strlen(name) + 1;
	if ((path = (char *)malloc(len)) == NULL)
		return ;
	memset(path, '\0', len);
	strcat(path, model->res_folder);
	strcat(path, name);
	model->mtl_fp = fopen(path, "r");
	free(path);
}