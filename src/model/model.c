#include "model.h"

static int		read_v(FILE *fp, t_model *model)
{
	t_list	*current;
	float	*tmp;

	if (!(current = new_elem(&(model->tmp_vertices))))
		return (0);
	tmp = (float *)(current.data);

	if (fscanf(file, "%f %f %f\n",
			&(tmp[0]),
			&(tmp[1]),
			&(tmp[2]))
		!= 3)
		return (0);

	return (1);
}

static int		read_f(FILE *fp, t_model *model)
{
	t_list	*current;
	float	*tmp;
	int		rd;
	float	face[4];

	rd = fscanf(file, "%f %f %f %f\n",
		&(face[0]),
		&(face[1]),
		&(face[2]),
		&(face[3]));

	if (rd == 4 || rd == 3)
	{
		if (!(current = new_elem(&(model->tmp_faces))))
			return (0);
		tmp = (float *)(current.data);
		tmp[0] = face[0];
		tmp[1] = face[1];
		tmp[2] = face[2];

		if (rd == 4)
		{
			if (!(current = new_elem(&(model->tmp_faces))))
				return (0);
			tmp = (float *)(current.data);
			tmp[0] = face[1];
			tmp[1] = face[2];
			tmp[2] = face[3];
		}
	}
	else
		return (0);

	return (1);
}

static t_model	*read_model(const char *path)
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
		free_model(model);
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (NULL);
	}

	model->tmp_vertices = NULL;	// vbo
	model->faces = NULL;		// ebo

	while (fscanf(file, "%ms", &type)) // read first word
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
			ret = 1; // skip line

		ft_strdel(&type);
		if (!ret)
		{
			fclose(fp);
			free_model(model);
			return (NULL);	
		}
	}

	fclose(fp);

	return (model);
}

static float	*process_model(const t_model *data)
{
	;
}

/*
** #		- comments, which are ignored
** mtllib	- the filename of a materials definition file
** o		- gives the name of a model.
** -			All data between this type and the next o type is a single model.
** v		- defines the x, y, and z value of a single vertex
** usemtl	- use a specific color and material definition for the following polygons.
** s		- turn smooth shading off or on; flat shading is used when smooth shading is off.
** f		- defines the vertices that compose a face. Note that faces can have more than 3 vertices.
** -			In this example the faces have four vertices which define quad polygons.
** -			These must be divided into triangles before WebGL rendering.
*/

float			*load_model(const char *path)
{
	float	*data;
	t_model	*model;

	if (!(model = read_model(path)))
		return (NULL);
	data = process_model(model);
	free_model(&model);
	return (data);
}
