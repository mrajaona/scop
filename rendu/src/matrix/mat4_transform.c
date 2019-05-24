#include "mat4_transform.h"

void			transform(const t_mat4 trans, t_mat4 dest)
{
	t_mat4	tmp;

	if (!dest)
		return ;
	mat4_eq(tmp, dest);
	mat4_mult(trans, tmp, dest);
}

void			translation(const t_vector mov, t_mat4 dest)
{
	t_mat4	translate_mat;

	if (!mov || !dest)
		return ;
	identity(translate_mat);
	mat4_set(translate_mat, 3, 0, mov[0]);
	mat4_set(translate_mat, 3, 1, mov[1]);
	mat4_set(translate_mat, 3, 2, mov[2]);
	mat4_set(translate_mat, 3, 3, 1);
	transform(translate_mat, dest);
}

void			scaling(const t_vector scale, t_mat4 dest)
{
	t_mat4	scale_mat;

	if (!scale || !dest)
		return ;
	mat4_clr(scale_mat);
	mat4_set(scale_mat, 0, 0, scale[0]);
	mat4_set(scale_mat, 1, 1, scale[1]);
	mat4_set(scale_mat, 2, 2, scale[2]);
	mat4_set(scale_mat, 3, 3, 1);
	transform(scale_mat, dest);
}
