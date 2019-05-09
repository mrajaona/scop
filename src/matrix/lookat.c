#include "matrix_lookat.h"

// a tester et corriger

// The camera in OpenGL cannot move and is defined
// to be located at (0,0,0) facing the negative Z direction

void			lookat(const t_vector eye, const t_vector target,
	const t_vector up, t_mat4 dest)
{
	t_vector	x; // right
	t_vector	y; // up
	t_vector	z; // direction

	t_mat4	res;

	fprintf(stdout, "\neye");
	vector_print(eye);
	fprintf(stdout, "\ntarget");
	vector_print(target);
	fprintf(stdout, "\nup");
	vector_print(up);

	fprintf(stdout, "\n------\n");

	coord_normalize(vector_sub(target, eye, z), z);
	fprintf(stdout, "\nz");
	vector_print(z);
	coord_normalize(up, y);
	fprintf(stdout, "\ny (tmp)");
	vector_print(y);
	coord_normalize(coord_cross_prod(z, y, x), x);
	fprintf(stdout, "\nx");
	vector_print(x);
	coord_normalize(coord_cross_prod(z, x, y), y);
	fprintf(stdout, "\ny");
	vector_print(y);

	fprintf(stdout, "\n------\n");

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

	mat4_print(dest);
}
