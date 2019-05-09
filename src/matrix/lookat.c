#include "matrix_lookat.h"

// a tester et corriger

/*
**  xx	xy	xz	0		1	0	0	-ex
**  yx	yy	yz	0		0	1	0	-ey
**  zx	zy	zz	0		0	0	1	-ez
**  0	0	0	1	x	0	0	0	1
*/

// The camera in OpenGL cannot move and is defined
// to be located at (0,0,0) facing the negative Z direction

void			lookat(const t_vector eye, const t_vector target,
	const t_vector up, t_mat4 dest)
{
	t_vector	tmp;

	t_vector	x; // right
	t_vector	y; // up
	t_vector	z; // direction

	t_mat4	lhs;

	coord_normalize(
		vector_sub(target, eye, z),
		z
	);

	coord_normalize(
		vector_sub(up, eye, tmp),
		tmp
	);

	coord_normalize(
		coord_cross_prod(z, tmp, x),
		x
	);

	coord_normalize(
		coord_cross_prod(z, x, y),
		y
	);

	identity(lhs);

	mat4_set(lhs, 0, 0, x[0]);
	mat4_set(lhs, 1, 0, x[1]);
	mat4_set(lhs, 2, 0, x[2]);

	mat4_set(lhs, 0, 1, y[0]);
	mat4_set(lhs, 1, 1, y[1]);
	mat4_set(lhs, 2, 1, y[2]);

	mat4_set(lhs, 0, 2, z[0]);
	mat4_set(lhs, 1, 2, z[1]);
	mat4_set(lhs, 2, 2, z[2]);

	t_mat4	rhs;

	identity(rhs);

	mat4_set(rhs, 3, 0, -1 * eye[0]);
	mat4_set(rhs, 3, 1, -1 * eye[1]);
	mat4_set(rhs, 3, 2, -1 * eye[2]);

	mat4_mult(lhs, rhs, dest);
}
