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

static void	read_lines(FILE *fp, t_model *model)
{
	char	*type;
	int		ret;

	while (fscanf(fp, "%ms", &type) != EOF) // read first word
	{
		if (!type)
		{
			free_model(&model);
			return ;
		}

		if (strcmp(type, "v") == 0)
			ret = read_v(fp, model);
		else if (strcmp( type, "f") == 0)
			ret = read_f(fp, model);
		else if (strcmp( type, "mtllib") == 0)
			ret = read_mtllib(fp, model);
		else if (strcmp( type, "usemtl") == 0)
			ret = read_usemtl(fp, model);
		else
			ret = skip_line(fp);

		free(type);
		type = NULL;

		if (!ret)
		{
			free_model(&model);
			return ;	
		}
	}
}

t_model		*read_model(const char *path)
{
	t_model	*model;
	FILE	*fp;

	if (!(model = (t_model *)malloc(sizeof(t_model))))
		return (NULL);

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
	model->faces = NULL;	// ebo
	model->nfaces = 0;

	read_lines(fp, model);
	fclose(fp);

	return (model);
}