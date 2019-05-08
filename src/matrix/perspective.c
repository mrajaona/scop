#include "matrix_perspective.h"

// a tester et corriger

/*
** 1 / (r * t)	0		0						0
** 0			1 / t	0						0
** 0			0		-(f + n) / (f - n)		-1
** 0			0		-(2 * f * n) / (f - n)	0
*/

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest)
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

/*
template <typename valType>
GLM_FUNC_QUALIFIER detail::tmat4x4<valType, defaultp> perspective
(
    valType const & fovy,
    valType const & aspect,
    valType const & zNear,
    valType const & zFar
)
{
    assert(aspect != valType(0));
    assert(zFar != zNear);

#ifdef GLM_FORCE_RADIANS
    valType const rad = fovy;
#else
#   pragma message("GLM: perspective function taking degrees as a parameter is deprecated.     #define GLM_FORCE_RADIANS before including GLM headers to remove this message.")
    valType const rad = glm::radians(fovy);
#endif

    valType tanHalfFovy = tan(rad / valType(2));

    detail::tmat4x4<valType, defaultp> Result(valType(0));
    Result[0][0] = valType(1) / (aspect * tanHalfFovy);
    Result[1][1] = valType(1) / (tanHalfFovy);
    Result[2][2] = - (zFar + zNear) / (zFar - zNear);
    Result[2][3] = - valType(1);
    Result[3][2] = - (valType(2) * zFar * zNear) / (zFar - zNear);
    return Result;
}
*/