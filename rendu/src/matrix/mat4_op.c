#include "mat4_op.h"

t_mat4_ptr		mat4_add(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;
	t_mat4			tmp;

	if (!lhs || (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		mat4_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(tmp, x, y,
				mat4_get(lhs, x, y) + mat4_get(rhs, x, y));
			x++;
		}
		y++;
	}
	mat4_eq(res, tmp);
	return (res);
}

t_mat4_ptr		mat4_sub(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;
	t_mat4			tmp;

	if (!lhs || (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	if (!rhs)
	{
		mat4_eq(res, lhs);
		return (res);
	}
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(tmp, x, y,
				mat4_get(lhs, x, y) - mat4_get(rhs, x, y));
			x++;
		}
		y++;
	}
	mat4_eq(res, tmp);
	return (res);
}

t_mat4_ptr		mat4_scalar(const t_mat4 mat, const int scalar, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;
	t_mat4			tmp;

	if (!mat || (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(tmp, x, y,
				mat4_get(mat, x, y) * scalar);
			x++;
		}
		y++;
	}
	mat4_eq(res, tmp);
	return (res);
}

/*
** res[x][y] = lhs x row . rhs y col
*/

static float	mult_step(const unsigned char x, const unsigned char y,
	const t_mat4 lhs, const t_mat4 rhs)
{
	float	step;
	unsigned char	i;

	step = 0;
	i = 0;
	while (i < 4)
	{
		step += mat4_get(lhs, i, y) * mat4_get(rhs, x, i);
		i++;
	}
	return (step);
}

t_mat4_ptr		mat4_mult(const t_mat4 lhs, const t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;
	t_mat4			tmp;

	if (!lhs || !rhs
		|| (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(tmp, x, y,
				mult_step(x, y, lhs, rhs));
			x++;
		}
		y++;
	}
	mat4_eq(res, tmp);
	return (res);
}
