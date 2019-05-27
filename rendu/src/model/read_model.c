#include "read_model.h"

int		skip_line(FILE *fp)
{
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return (1);
	}

	return (1);
}

t_model		*read_model(const char *path)
{
	t_model	*model;
	FILE	*fp;
	char	*type;
	int		ret;

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

	while (fscanf(fp, "%ms", &type) != EOF) // read first word
	{
		if (!type)
		{
			fclose(fp);
			free_model(&model);
			return (NULL);
		}

		if (strcmp(type, "v") == 0)
			ret = read_v(fp, model);
		else if (strcmp( type, "f") == 0)
			ret = read_f(fp, model);
		else
			ret = skip_line(fp);

		free(type);
		type = NULL;

		if (!ret)
		{
			fclose(fp);
			free_model(&model);
			return (NULL);	
		}
	}

	fclose(fp);

	return (model);
}