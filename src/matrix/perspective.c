#include "matrix_perspective.h"

// a tester et corriger

/*
** 1 / (r * t)	0		0						0
** 0			1 / t	0						0
** 0			0		-(f + n) / (f - n)		-1
** 0			0		-(2 * f * n) / (f - n)	0
*/

void	perspective(const float vfov, const float ratio, const float planes[2], t_mat4 dest)
{
	float	tan_vfov;

	clear_matrix(dest);
	tan_vfov = tanf(vfov / 2);
	mat4_set(dest, 0, 0, 1 / (ratio * tan_vfov));
	mat4_set(dest, 1, 1, 1 / tan_vfov);
	mat4_set(dest, 2, 2,
		-1 * (planes[FAR_PLANE] + planes[NEAR_PLANE])
			/ (planes[FAR_PLANE] - planes[NEAR_PLANE]));
	mat4_set(dest, 2, 3, -1);
	mat4_set(dest, 3, 2,
		(-2 * planes[FAR_PLANE] * planes[NEAR_PLANE])
			/ (planes[FAR_PLANE] - planes[NEAR_PLANE]));
}
