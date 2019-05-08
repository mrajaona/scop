#include "matrix_lookat.h"
#include "error.h"

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

	coord_normalize(cam_direction, d);
	coord_normalize(cam_up, u);
	coord_normalize(cam_right, r);

	identity(lhs);

	fprintf(stdout, "lhs\n");
	mat4_set(lhs, 0, 0, r[0]);
	mat4_set(lhs, 1, 0, r[1]);
	mat4_set(lhs, 2, 0, r[2]);

	mat4_set(lhs, 0, 1, u[0]);
	mat4_set(lhs, 1, 1, u[1]);
	mat4_set(lhs, 2, 1, u[2]);

	mat4_set(lhs, 0, 2, d[0]);
	mat4_set(lhs, 1, 2, d[1]);
	mat4_set(lhs, 2, 2, d[2]);

	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(lhs, 0, 0),
		mat4_get(lhs, 1, 0),
		mat4_get(lhs, 2, 0),
		mat4_get(lhs, 3, 0)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(lhs, 0, 1),
		mat4_get(lhs, 1, 1),
		mat4_get(lhs, 2, 1),
		mat4_get(lhs, 3, 1)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(lhs, 0, 2),
		mat4_get(lhs, 1, 2),
		mat4_get(lhs, 2, 2),
		mat4_get(lhs, 3, 2)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(lhs, 0, 3),
		mat4_get(lhs, 1, 3),
		mat4_get(lhs, 2, 3),
		mat4_get(lhs, 3, 3)
	);

	fflush(stdout);

	t_mat4	rhs;

	identity(rhs);

	mat4_set(rhs, 3, 0, -1 * eye[0]);
	mat4_set(rhs, 3, 1, -1 * eye[1]);
	mat4_set(rhs, 3, 2, -1 * eye[2]);

	fprintf(stdout, "rhs\n");
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(rhs, 0, 0),
		mat4_get(rhs, 1, 0),
		mat4_get(rhs, 2, 0),
		mat4_get(rhs, 3, 0)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(rhs, 0, 1),
		mat4_get(rhs, 1, 1),
		mat4_get(rhs, 2, 1),
		mat4_get(rhs, 3, 1)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(rhs, 0, 2),
		mat4_get(rhs, 1, 2),
		mat4_get(rhs, 2, 2),
		mat4_get(rhs, 3, 2)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(rhs, 0, 3),
		mat4_get(rhs, 1, 3),
		mat4_get(rhs, 2, 3),
		mat4_get(rhs, 3, 3)
	);

	mat4_mult(lhs, rhs, dest);

	fprintf(stdout, "dest\n");
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(dest, 0, 0),
		mat4_get(dest, 1, 0),
		mat4_get(dest, 2, 0),
		mat4_get(dest, 3, 0)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(dest, 0, 1),
		mat4_get(dest, 1, 1),
		mat4_get(dest, 2, 1),
		mat4_get(dest, 3, 1)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(dest, 0, 2),
		mat4_get(dest, 1, 2),
		mat4_get(dest, 2, 2),
		mat4_get(dest, 3, 2)
	);
	fprintf(stdout, "% .f % .f % .f % .f\n",
		mat4_get(dest, 0, 3),
		mat4_get(dest, 1, 3),
		mat4_get(dest, 2, 3),
		mat4_get(dest, 3, 3)
	);

	fflush(stdout);

}
