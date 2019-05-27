#include "read_obj.h"

int	read_v(FILE *fp, t_model *model)
{
	t_list	*current;
	float	*tmp;

	if (!(current = new_elem(&(model->vertices), 3 * sizeof(float))))
		return (0);
	model->nvertices++;
	tmp = (float *)(current->data);
	if (fscanf(fp, "%f %f %f\n",
			&(tmp[0]),
			&(tmp[1]),
			&(tmp[2]))
		!= 3)
		return (0);
	return (1);
}

int	read_f(FILE *fp, t_model *model)
{
	t_list	*current;
	GLuint	*tmp;
	int		rd;
	GLuint	face[4];

	rd = fscanf(fp, "%u %u %u %u\n",
		&(face[0]),
		&(face[1]),
		&(face[2]),
		&(face[3]));

	if (face[0] == 0
		|| face[1] == 0
		|| face[2] == 0
		|| (rd == 4 && face[3] == 0))
		return (0);

	if (rd == 4 || rd == 3)
	{
		if (!(current = new_elem(&(model->faces), 3 * sizeof(GLuint))))
			return (0);
		model->nfaces++;
		tmp = (GLuint *)(current->data);
		tmp[0] = face[0] - 1;
		tmp[1] = face[1] - 1;
		tmp[2] = face[2] - 1;

		if (rd == 4)
		{
			if (!(current = new_elem(&(model->faces), 3 * sizeof(GLuint))))
				return (0);
			model->nfaces++;
			tmp = (GLuint *)(current->data);
			tmp[0] = face[2] - 1;
			tmp[1] = face[3] - 1;
			tmp[2] = face[0] - 1;
		}
	}
	else
		return (0);

	return (1);
}

