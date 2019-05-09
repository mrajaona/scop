#include "vector.h"

void	vector_print(const t_vector vec)
{
	fprintf(stdout, "\n% .2f\n% .2f\n% .2f\n% .2f\n",
		vec[0], vec[1], vec[2], vec[3]);
	fflush(stdout);
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
	res = (lhs[0] * rhs[0])
		+ (lhs[1] * rhs[1])
		+ (lhs[2] * rhs[2]);
	return (res);
}

void			coord_normalize(const t_vector vector, t_vector dest)
{
	float		len;
	float		sqlen;
	t_vector	tmp;

	sqlen = (vector[0] * vector[0])
		+ (vector[1] * vector[1])
		+ (vector[2] * vector[2]);
	len = sqrtf(sqlen);
	tmp[0] = sqlen ? (vector[0] / len) : 0;
	tmp[1] = sqlen ? (vector[1] / len) : 0;
	tmp[2] = sqlen ? (vector[2] / len) : 0;
	tmp[3] = 1;
	vector_eq(dest, tmp);
}
