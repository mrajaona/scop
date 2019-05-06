#include "vector.h"

void			normalize(t_vector vector, t_vector dest)
{
	float	len;

	len = sqrtf(
		(vector[0] * vector[0])
		+ (vector[1] * vector[1])
		+ (vector[2] * vector[2])
	);
	dest[0] = vector[0] / len;
	dest[1] = vector[1] / len;
	dest[2] = vector[2] / len;
	dest[3] = 1;
}

/*
** 0
** 0
** 0
** 1
*/

void		clear_vector(t_vector vec)
{
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 0;
	vec[3] = 1;
}

void		vector_eq(t_vector dst, t_vector src)
{
	unsigned char	y;

	y = 0;
	while (y < 4)
	{
		dst[y] = src[y];
		y++;
	}
}

t_vector_ptr	vector_add(t_vector lhs, t_vector rhs, t_vector res)
{
	unsigned char	y;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		res[y] = lhs[y] + rhs[y];
		y++;
	}
	return (res);
}

t_vector_ptr	vector_sub(t_vector lhs, t_vector rhs, t_vector res)
{
	unsigned char	y;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		res[y] = lhs[y] - rhs[y];
		y++;
	}
	return (res);
}

t_vector_ptr	vector_scalar(t_vector vec, int scalar, t_vector res)
{
	unsigned char	y;

	if (!vec || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		res[y] = vec[y] * scalar;
		y++;
	}
	return (res);
}
