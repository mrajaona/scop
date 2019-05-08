#include "matrix_lookat.h"

// a tester et corriger

/*
**  rx	ry	rz	0		1	0	0	-ex
**  ux	uy	uz	0		0	1	0	-ey
**  dx	dy	dz	0		0	0	1	-ez
**  0	0	0	1	x	0	0	0	1
*/

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
	vector_scalar(cam_up, -1, cam_up); // fix foireux

	coord_normalize(cam_direction, d);
	coord_normalize(cam_up, u);
	coord_normalize(cam_right, r);

	identity(lhs);

	mat4_mult(lhs, rhs, dest);
}
