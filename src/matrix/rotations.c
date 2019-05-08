# include "matrix_rotations.h"

/*
** Rotations
** angle must be in rad
*/

float				deg_to_rad(const float angle)
{
	return (angle * (M_PI / 180.0));
}

float				rad_to_deg(const float angle)
{
	return (angle * (180.0 / M_PI));
}

/*
** 1 0  0 0
** 0 c -s 0
** 0 s  c 0
** 0 0  0 1
*/

void			rotatex(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
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

void			rotatey(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
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

void			rotatez(const float angle, t_mat4 dest)
{
	t_mat4	rotate_mat;
	float	c;
	float	s;

	if (!dest)
		return ;
	identity(rotate_mat);
	c = cosf(angle);
	s = sinf(angle);
	mat4_set(rotate_mat, 0, 0, c);
	mat4_set(rotate_mat, 1, 0, -1 * s);
	mat4_set(rotate_mat, 0, 1, s);
	mat4_set(rotate_mat, 1, 1, c);
	transform(rotate_mat, dest);
}
