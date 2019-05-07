#include "matrix_op.h"

void			coord_to_vec(float x, float y, float z, t_vector dest)
{
	dest[0] = x;
	dest[1] = y;
	dest[2] = z;
	dest[3] = 1;
}


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

void			translation(t_vector mov, t_mat4 dest)
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

void			rotatey(t_angle angle, t_mat4 dest)
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

void			rotatez(t_angle angle, t_mat4 dest)
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

// a tester et corriger


// It seems you already have a camera pos (p), target (l) and up (u) vectors.
// To calculate right, find the cross product of (p - l) and (u - p).
// This will give you a vector orthogonal to both, the "right" vector.

void			lookat(t_vector eye, t_vector target, t_vector up, t_mat4 dest)
{
	t_vector	cam_direction;
	t_vector	tmp;

	t_vector	cam_right;
	t_vector	cam_up;

	t_vector	r; // right
	t_vector	u; // up
	t_vector	d; // direction

	t_mat4	lhs;

	vector_sub(target, eye, cam_direction);
	vector_sub(up, eye, tmp);
	coord_cross_prod(cam_direction, tmp, cam_right);

	coord_cross_prod(cam_direction, cam_right, cam_up);

	coord_normalize(cam_direction, d);
	coord_normalize(cam_up, u);
	coord_normalize(cam_right, r);

	identity(lhs);

	mat4_set(lhs, 0, 0, r[0]);
	mat4_set(lhs, 1, 0, r[1]);
	mat4_set(lhs, 2, 0, r[2]);

	mat4_set(lhs, 0, 1, u[0]);
	mat4_set(lhs, 1, 1, u[1]);
	mat4_set(lhs, 2, 1, u[2]);

	mat4_set(lhs, 0, 2, d[0]);
	mat4_set(lhs, 1, 2, d[1]);
	mat4_set(lhs, 2, 2, d[2]);

	t_mat4	rhs;

	identity(rhs);

	mat4_set(rhs, 3, 0, -1 * eye[0]);
	mat4_set(rhs, 3, 1, -1 * eye[1]);
	mat4_set(rhs, 3, 2, -1 * eye[2]);

	mat4_mult(lhs, rhs, dest);
}
