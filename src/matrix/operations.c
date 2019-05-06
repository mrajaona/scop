#include "matrix_op.h"

void		mat4_vector_prod(t_mat4 lhs, t_vector rhs, t_vector res)
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

static void	transform(t_mat4 trans, t_mat4 dest)
{
	t_mat4	tmp_mat;

	if (!dest)
		return ;
	mat4_eq(tmp_mat, dest);
	mat4_mult(trans, tmp_mat, dest);
}

void			translation(t_3d_coord *mov, t_mat4 dest)
{
	t_mat4	translate_mat;

	if (!mov || !dest)
		return ;
	identity(translate_mat);
	mat4_set(translate_mat, 3, 0, mov->x);
	mat4_set(translate_mat, 3, 1, mov->y);
	mat4_set(translate_mat, 3, 2, mov->z);
	mat4_set(translate_mat, 3, 3, 1);
	transform(translate_mat, dest);
}

void			scaling(t_scale *scale, t_mat4 dest)
{
	t_mat4	scale_mat;

	if (!scale || !dest)
		return ;
	clear_matrix(scale_mat);
	mat4_set(scale_mat, 0, 0, scale->sx);
	mat4_set(scale_mat, 1, 1, scale->sy);
	mat4_set(scale_mat, 2, 2, scale->sz);
	mat4_set(scale_mat, 3, 3, 1);
	transform(scale_mat, dest);
}

/*
** Rotations
** angle must be in rad
*/

#define degreesToRadians(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / M_PI)

float				deg_to_rad(float angle)
{
	return (angle * (M_PI / 180.0));
}

float				rad_to_deg(float angle)
{
	return (angle * (180.0 / M_PI));
}

/*
** 1 0  0 0
** 0 c -s 0
** 0 s  c 0
** 0 0  0 1
*/

void			rotatex(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 1, 1, c);
	mat4_set(rotate_mat, 2, 1, -1 * s);
	mat4_set(rotate_mat, 1, 2, s);
	mat4_set(rotate_mat, 2, 2, c);
	transform(rotate_mat, dest);
}

/*
**  c 0 s 0
**  0 1 0 0
** -s 0 c 0
**  0 0 0 1
*/

void			rotatey(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 2, 0, s);
	mat4_set(rotate_mat, 0, 2, -1 * s);
	mat4_set(rotate_mat, 2, 2, c);
	transform(rotate_mat, dest);
}

/*
** c -s 0 0
** s  c 0 0
** 0  0 1 0
** 0  0 0 1
*/

void			rotatez(t_angle angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cos(angle);
	s = sin(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 1, 0, -1 * s);
	mat4_set(rotate_mat, 0, 1, s);
	mat4_set(rotate_mat, 1, 1, c);
	transform(rotate_mat, dest);
}
