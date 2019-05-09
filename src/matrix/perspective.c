#include "matrix_perspective.h"

// a tester et corriger

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest)
{
	const float	c = cos(vfov / 2);
	const float	s = sinf(vfov / 2);
	const float	near = planes[NEAR_PLANE];
	const float	far = planes[FAR_PLANE];
	float		cotan;

	clear_matrix(dest);
	if (near == far || s == 0.0f || ratio == 0.0f)
		return ;
	cotan = c / s;
	mat4_set(dest, 0, 0, cotan / ratio);
	mat4_set(dest, 1, 1, cotan);
	mat4_set(dest, 2, 2, -1 * (far + near) / (far - near));
	mat4_set(dest, 2, 3, -1);
	mat4_set(dest, 3, 2, (-2 * far * near) / (far - near));
}
/*
void GLAPIENTRY gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
    GLdouble m[4][4];
    double sine, cotangent, deltaZ;
    double radians = fovy / 2 * __glPi / 180;

    deltaZ = zFar - zNear;
    sine = sin(radians);
    if ((deltaZ == 0) || (sine == 0) || (aspect == 0)) {
    return;
    }
    cotangent = COS(radians) / sine;

    __gluMakeIdentityd(&m[0][0]);
    m[0][0] = cotangent / aspect;
    m[1][1] = cotangent;
    m[2][2] = -(zFar + zNear) / deltaZ;
    m[2][3] = -1;
    m[3][2] = -2 * zNear * zFar / deltaZ;
    m[3][3] = 0;
    glMultMatrixd(&m[0][0]);
}
*/