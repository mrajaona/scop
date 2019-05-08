#include "vector.h"

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

void		vector_eq(t_vector dst, const t_vector src)
{
	unsigned char	y;

	y = 0;
	while (y < 4)
	{
		dst[y] = src[y];
		y++;
	}
}

t_vector_ptr	vector_add(const t_vector lhs, const t_vector rhs, t_vector res)
{
	unsigned char	y;
	t_vector	tmp;

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
		tmp[y] = lhs[y] + rhs[y];
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}

t_vector_ptr	vector_sub(const t_vector lhs, const t_vector rhs, t_vector res)
{
	unsigned char	y;
	t_vector	tmp;

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
		tmp[y] = lhs[y] - rhs[y];
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}

t_vector_ptr	vector_scalar(const t_vector vec, const int scalar, t_vector res)
{
	unsigned char	y;
	t_vector	tmp;

	if (!vec || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		tmp[y] = vec[y] * scalar;
		y++;
	}
	vector_eq(res, tmp);
	return (res);
}

t_vector_ptr	coord_cross_prod(const t_vector lhs, const t_vector rhs, t_vector res)
{
	t_vector	tmp;

	tmp[0] = (lhs[1] * rhs[2]) - (lhs[2] * rhs[1]);
	tmp[1] = (lhs[2] * rhs[0]) - (lhs[0] * rhs[2]);
	tmp[2] = (lhs[0] * rhs[1]) - (lhs[1] * rhs[0]);
	tmp[3] = 1;
	vector_eq(res, tmp);
	return (res);
}

float			coord_dot_prod(const t_vector lhs, const t_vector rhs)
{
	float	res;
	float	rsum;

	rsum = rhs[0] + rhs[1] + rhs[2];
	res = (lhs[0] * rsum)
		+ (lhs[1] * rsum)
		+ (lhs[2] * rsum);
	return (res);
}

void			coord_normalize(const t_vector vector, t_vector dest)
{
	float		len;
	t_vector	tmp;

	len = sqrtf(
		(vector[0] * vector[0])
		+ (vector[1] * vector[1])
		+ (vector[2] * vector[2])
	);
	tmp[0] = vector[0] / len;
	tmp[1] = vector[1] / len;
	tmp[2] = vector[2] / len;
	tmp[3] = 1;
	vector_eq(dest, tmp);
}
