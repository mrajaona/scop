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

void			lookat(t_vector eye, t_vector center, t_vector up, t_mat4 dest)
{
	t_vector	s;					// up x f
	t_vector	t;					// norm(s) x direction_final
	t_vector	final_direction;	// norm(center - eye)

	t_vector	f;
	t_vector	norm_s;

	vector_sub(center, eye, final_direction);
	coord_normalize(final_direction, f);

	coord_scalar_prod(f, up, s);
	coord_normalize(s, norm_s);
	coord_scalar_prod(norm_s, f, t);

	mat4_set(dest, 0, 0, s[0]);
	mat4_set(dest, 1, 0, s[1]);
	mat4_set(dest, 2, 0, s[2]);
	mat4_set(dest, 3, 0, 0);

	mat4_set(dest, 0, 1, t[0]);
	mat4_set(dest, 1, 1, t[1]);
	mat4_set(dest, 2, 1, t[2]);
	mat4_set(dest, 3, 1, 0);

	mat4_set(dest, 0, 2, -1 * f[0]);
	mat4_set(dest, 1, 2, -1 * f[1]);
	mat4_set(dest, 2, 2, -1 * f[2]);
	mat4_set(dest, 3, 2, 0);

	mat4_set(dest, 0, 3, 0);
	mat4_set(dest, 1, 3, 0);
	mat4_set(dest, 2, 3, 0);
	mat4_set(dest, 3, 3, 1);
}
