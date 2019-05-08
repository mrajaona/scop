#include "matrix_op.h"

void			coord_to_vec(const float x, const float y, const float z,
	t_vector dest)
{
	dest[0] = x;
	dest[1] = y;
	dest[2] = z;
	dest[3] = 1;
}


void		mat4_vector_prod(const t_mat4 lhs, const t_vector rhs, t_vector res)
{
	unsigned char	x;
	unsigned char	y;

	if (!lhs || !rhs || !res)
		return ;
	y = 0;
	while (y < 4)
	{
		x = 0;
		res[y] = 0;
		while (x < 4)
		{
			res[y] += mat4_get(lhs, x, y) * rhs[y];
			x++;
		}
		y++;
	}
}

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
	clear_matrix(scale_mat);
	mat4_set(scale_mat, 0, 0, scale[0]);
	mat4_set(scale_mat, 1, 1, scale[1]);
	mat4_set(scale_mat, 2, 2, scale[2]);
	mat4_set(scale_mat, 3, 3, 1);
	transform(scale_mat, dest);
}
