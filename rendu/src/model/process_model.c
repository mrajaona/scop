#include "process_model.h"

int	process_model(const t_model *model, t_data *data)
{
	t_list			*list;
	unsigned int	i;
	size_t			size;

	data->nfaces = model->nfaces;

	float			*vertices;
	float			*vertice;

	size = model->nvertices * N_DATA_PER_VERTICE;
	if (!(vertices = (float *)malloc(size * sizeof(float))))
		return (0);
	list = model->vertices;
	vertice = vertices;
	while (list)
	{
		i = 0;
		while (i < N_DATA_PER_VERTICE)
		{
			vertice[i] = ((float *)(list->data))[i];
			i++;
		}
		list = list->next;
		vertice += N_DATA_PER_VERTICE;
	}
	vbo(&(data->arrays.vbo), vertices, size);
	free(vertices);
	
	vao(&(data->arrays.vao));

	GLuint			*elements;
	GLuint			*element;

	size = model->nfaces * N_VERTICES_PER_FACE;
	if (!(elements = (GLuint *)malloc(size * sizeof(GLuint))))
		return (0);
	list = model->faces;
	element = elements;
	while (list)
	{
		i = 0;
		while (i < N_VERTICES_PER_FACE)
		{
			element[i] = ((GLuint *)(list->data))[i];
			i++;
		}
		list = list->next;
		element += N_VERTICES_PER_FACE;
	}
	ebo(&(data->arrays.ebo), elements, size);
	free(elements);

	return (1);
}