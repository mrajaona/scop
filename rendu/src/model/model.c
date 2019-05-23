#include "model.h"

static	t_list	*new_elem(t_list **list, size_t data_size)
{
	t_list	*elem;
	t_list	*prev;

	if (!list || !(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);

	if (!(elem->data = malloc(data_size)))
	{
		free(elem);
		return (NULL);
	}

	elem->next = NULL;
	if (!(*list))
		*list = elem;
	else
	{
		prev = *list;
		while (prev->next)
			prev = prev->next;
		prev->next = elem;
	}
	return (elem);
}

static void		free_list(t_list **list)
{
	t_list	*next;
	t_list	*cur;

	if (!list)
		return ;
	cur = *list;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*list = NULL;
}

static void		free_model(t_model **model)
{
	if (!model || !(*model))
		return ;
	free_list(&((*model)->vertices));
	free_list(&((*model)->faces));
	free(*model);
	*model = NULL;
}

static int		read_v(FILE *fp, t_model *model)
{
	t_list	*current;
	float	*tmp;

	if (!(current = new_elem(&(model->vertices), 3 * sizeof(float))))
		return (0);
	tmp = (float *)(current->data);

	if (fscanf(fp, "%f %f %f\n",
			&(tmp[0]),
			&(tmp[1]),
			&(tmp[2]))
		!= 3)
		return (0);

	return (1);
}

static int		read_f(FILE *fp, t_model *model)
{
	t_list			*current;
	unsigned int	*tmp;
	int				rd;
	unsigned int	face[4];


	rd = fscanf(fp, "%u %u %u %u\n",
		&(face[0]),
		&(face[1]),
		&(face[2]),
		&(face[3]));

	printf("\nrd : %i\n", rd); fflush(stdout);
	printf("\nf : %u %u %u %u\n",
		face[0],
		face[1],
		face[2],
		face[3]
	);
	fflush(stdout);

	if (rd == 4 || rd == 3)
	{
		if (!(current = new_elem(&(model->faces), 3 * sizeof(unsigned int))))
			return (0);
		tmp = (unsigned int *)(current->data);
		tmp[0] = face[0];
		tmp[1] = face[1];
		tmp[2] = face[2];

		if (rd == 4)
		{
			if (!(current = new_elem(&(model->faces), 3 * sizeof(unsigned int))))
				return (0);
			tmp = (unsigned int *)(current->data);
			tmp[0] = face[1];
			tmp[1] = face[2];
			tmp[2] = face[3];
		}
	}
	else
		return (0);

	return (1);
}

static int		skip_line(FILE *fp)
{
	char	s[1025];

	while (fgets(s, 1025, fp) != NULL)
	{
		if (strchr(s, '\n'))
			return (1);
	}

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
		free_model(&model);
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (NULL);
	}

	model->vertices = NULL;	// vbo
	model->faces = NULL;		// ebo

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

static float	*process_model(const t_model *data)
{
	t_list	*list;

	printf("vertices\n");
	list = data->vertices;
	while (list)
	{
		printf("v %+f %+f %+f\n",
			((float *)(list->data))[0],
			((float *)(list->data))[1],
			((float *)(list->data))[2]
			);
		list = list->next;
	}

	printf("faces\n");
	list = data->faces;
	while (list)
	{
		printf("f %u %u %u\n",
			((unsigned int *)(list->data))[0],
			((unsigned int *)(list->data))[1],
			((unsigned int *)(list->data))[2]
			);
		list = list->next;
	}

	fflush(stdout);

	return (NULL);
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
