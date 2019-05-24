#include "lookat.h"

// The camera in OpenGL cannot move and is defined
// to be located at (0,0,0) facing the negative Z direction

void			lookat(const t_vector eye, const t_vector target,
	const t_vector up, t_mat4 dest)
{
	t_vector	x; // right
	t_vector	y; // up
	t_vector	z; // direction
	t_mat4		res;

	coord_normalize(vector_sub(target, eye, z), z);
	coord_normalize(up, y);
	coord_normalize(coord_cross_prod(z, y, x), x);
	coord_normalize(coord_cross_prod(x, z, y), y);

	identity(res);

	mat4_set(res, 0, 0, x[0]);
	mat4_set(res, 1, 0, x[1]);
	mat4_set(res, 2, 0, x[2]);

	mat4_set(res, 0, 1, y[0]);
	mat4_set(res, 1, 1, y[1]);
	mat4_set(res, 2, 1, y[2]);

	mat4_set(res, 0, 2, -1 * z[0]);
	mat4_set(res, 1, 2, -1 * z[1]);
	mat4_set(res, 2, 2, -1 * z[2]);

	mat4_set(res, 3, 0, -1 * coord_dot_prod(x, eye));
	mat4_set(res, 3, 1, -1 * coord_dot_prod(y, eye));
	mat4_set(res, 3, 2, coord_dot_prod(z, eye));

	mat4_eq(dest, res);
}
