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

static void	transform(const t_mat4 trans, t_mat4 dest)
{
	t_mat4	tmp_mat;

	if (!dest)
		return ;
	mat4_eq(tmp_mat, dest);
	mat4_mult(trans, tmp_mat, dest);
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

void			scaling(const t_scale *scale, t_mat4 dest)
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

// a tester et corriger


// It seems you already have a camera pos (p), target (l) and up (u) vectors.
// To calculate right, find the cross product of (p - l) and (u - p).
// This will give you a vector orthogonal to both, the "right" vector.

void			lookat(const t_vector eye, const t_vector target,
	const t_vector up, t_mat4 dest)
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
