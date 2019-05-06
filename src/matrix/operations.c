#include "matrix_op.h"

t_vector_ptr		mat4_vector_prod(t_mat4 lhs, t_vector rhs, t_vector res)
{
	unsigned char	x;
	unsigned char	y;

	if (!lhs || !rhs
		|| (!res && !(res = (t_vector_ptr)malloc(4 * sizeof(double)))))
		return (NULL);
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
	return (res);
}

// todo : init dest identity
static t_mat4_ptr	transform(t_mat4 trans, t_mat4 dest)
{
	t_mat4	tmp_mat;

	if (!dest)
	{
		if (!(dest = (t_mat4_ptr)malloc(16 * sizeof(double))))
			return (NULL);
		identity(dest);
	}
	mat4_eq(tmp_mat, dest);
	return (mat4_mult(trans, tmp_mat, dest));
}

t_mat4_ptr			translation(t_3d_coord *mov, t_mat4 dest)
{
	t_mat4	translate_mat;

	identity(translate_mat);
	mat4_set(translate_mat, 3, 0, mov->x);
	mat4_set(translate_mat, 3, 1, mov->y);
	mat4_set(translate_mat, 3, 2, mov->z);
	mat4_set(translate_mat, 3, 3, 1);
	return (transform(translate_mat, dest));
}

t_mat4_ptr			scaling(t_scale *scale, t_mat4 dest)
{
	t_mat4	scale_mat;

	clear_matrix(scale_mat);
	mat4_set(scale_mat, 0, 0, scale->sx);
	mat4_set(scale_mat, 1, 1, scale->sy);
	mat4_set(scale_mat, 2, 2, scale->sz);
	mat4_set(scale_mat, 3, 3, 1);
	return (transform(scale_mat, dest));
}

/*
** 1 0  0 0
** 0 c -s 0
** 0 s  c 0
** 0 0  0 1
*/

t_mat4_ptr			rotatex(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	double	c;
	double	s;

	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 1, 1, c);
	mat4_set(rotate_mat, 2, 1, -1 * s);
	mat4_set(rotate_mat, 1, 2, s);
	mat4_set(rotate_mat, 2, 2, c);
	return (transform(rotate_mat, dest));
}

/*
**  c 0 s 0
**  0 1 0 0
** -s 0 c 0
**  0 0 0 1
*/

t_mat4_ptr			rotatey(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	double	c;
	double	s;

	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 2, 0, s);
	mat4_set(rotate_mat, 0, 2, -1 * s);
	mat4_set(rotate_mat, 2, 2, c);
	return (transform(rotate_mat, dest));
}

/*
** c -s 0 0
** s  c 0 0
** 0  0 1 0
** 0  0 0 1
*/

t_mat4_ptr			rotatez(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	double	c;
	double	s;

	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 1, 0, -1 * s);
	mat4_set(rotate_mat, 0, 1, s);
	mat4_set(rotate_mat, 1, 1, c);
	return (transform(rotate_mat, dest));
}
