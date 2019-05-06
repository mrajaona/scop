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
	unsigned char	x;
	unsigned char	y;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(double)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res[x + (4 * y)] = lhs[x + (4 * y)] + rhs[x + (4 * y)];
			x++;
		}
		y++;
	}
	return (res);
}

t_vector_ptr	vector_sub(t_vector lhs, t_vector rhs, t_vector res)
{
	unsigned char	x;
	unsigned char	y;

	if (!lhs || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(double)))))
		return (NULL);
	if (!rhs)
	{
		vector_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res[x + (4 * y)] = lhs[x + (4 * y)] - rhs[x + (4 * y)];
			x++;
		}
		y++;
	}
	return (res);
}

t_vector_ptr	vector_scalar(t_vector vec, int scalar, t_vector res)
{
	unsigned char	x;
	unsigned char	y;

	if (!vec || (!res && !(res = (t_vector_ptr)malloc(16 * sizeof(double)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			res[x + (4 * y)] = vec[x + (4 * y)] * scalar;
			x++;
		}
		y++;
	}
	return (res);
}
