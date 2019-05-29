#include "read_model.h"

int			skip_line(FILE *fp)
{
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return (1);
	}

	return (1);
}

static void	read_lines(FILE *fp, t_model **model)
{
	const char		*str_tab[] = {"v", "f", "s", "mtllib", "usemtl"};
	int 			(*fn_tab[])(FILE *, t_model *) = {&read_v, &read_f, &read_s, &read_mtllib, &read_usemtl};
	char			*type;
	int				ret;
	unsigned int	i;

	while (fscanf(fp, "%ms", &type) != EOF) // read first word
	{
		if (!type)
		{
			free_model(model);
			return ;
		}

		i = 0;
		while (i < 5)
		{
			if (strcmp(type, str_tab[i]) == 0)
			{
				ret = fn_tab[i](fp, *model);
				break ;
			}
			i++;
		}
		if (i == 5)
			ret = skip_line(fp);

		free(type);
		type = NULL;

		if (!ret)
		{
			free_model(model);
			return ;	
		}
	}
}

char		*get_res_folder(const char *path)
{
	char	*tmp;
	char	*folder;

	folder = (char *)malloc(strlen(path) + 1);
	strcpy(folder, path);
	folder[strlen(path)] = '\0';

	tmp = strrchr(folder, '/');
	if (!tmp)
	{
		if ((folder = (char *)realloc(folder, 3)) != NULL)
			strcpy(folder, "./");
	}
	else
	{
		*(tmp + 1) = '\0';
		folder = (char *)realloc(folder, strlen(folder) + 1);
	}
	return (folder);
}

t_model		*read_model(const char *path)
{
	t_model	*model;
	FILE	*fp;

	if (!(model = (t_model *)malloc(sizeof(t_model))))
		return (NULL);

	if (!(model->res_folder = get_res_folder(path)))
	{
		free_model(&model);
		return (NULL);
	}

	fp = fopen(path, "r");

	if (!fp)
	{
		free_model(&model);
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (NULL);
	}

	model->vertices = NULL;	// vbo
	model->nvertices = 0;
	model->faces = NULL;	// ibo
	model->nfaces = 0;
	model->mtl_fp = NULL;

	read_lines(fp, &model);
	fclose(fp);

	return (model);
}