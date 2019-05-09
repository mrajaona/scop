#include "matrix_perspective.h"

// a tester et corriger

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest)
{
	const float	near = planes[NEAR_PLANE];
	const float	far = planes[FAR_PLANE];
	const float	htan = tanf(vfov / 2);

	clear_matrix(dest);
	if (near == far || htan == 0.0f || ratio == 0.0f)
		return ;
	mat4_set(dest, 0, 0, htan / ratio);
	mat4_set(dest, 1, 1, htan);
	mat4_set(dest, 2, 2, -1 * (far + near) / (far - near));
	mat4_set(dest, 3, 2, -1);
	mat4_set(dest, 2, 3, (-2 * far * near) / (far - near));
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

    valType const rad = fovy;

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
