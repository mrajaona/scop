#include "matrix.h"

void		mat4_set(t_mat4 mat, unsigned char x, unsigned char y, float value)
{
	if (x >= 4 || y >= 4)
		return ;
	mat[x + (4 * y)] = value;
}

float		mat4_get(t_mat4 mat, unsigned char x, unsigned char y)
{
	if (x >= 4 || y >= 4)
		return (0);
	return (mat[x + (4 * y)]);
}

/*
** 0 0 0 0
** 0 0 0 0
** 0 0 0 0
** 0 0 0 0
*/

void		clear_matrix(t_mat4 mat)
{
	unsigned char	x;
	unsigned char	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(mat, x, y, 0);
			x++;
		}
		y++;
	}
}

/*
** 1 0 0 0
** 0 1 0 0
** 0 0 1 0
** 0 0 0 1
*/

void		identity(t_mat4 mat)
{
	unsigned char	x;
	unsigned char	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (x == y)
				mat4_set(mat, x, y, 1);
			else
				mat4_set(mat, x, y, 0);
			x++;
		}
		y++;
	}
}

void		mat4_eq(t_mat4 dst, t_mat4 src)
{
	unsigned char	x;
	unsigned char	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(dst, x, y,
				mat4_get(src, x, y));
			x++;
		}
		y++;
	}	
}

t_mat4_ptr		mat4_add(t_mat4 lhs, t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;

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
			mat4_set(res, x, y,
				mat4_get(lhs, x, y) + mat4_get(rhs, x, y));
			x++;
		}
		y++;
	}
	return (res);
}

t_mat4_ptr		mat4_sub(t_mat4 lhs, t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;

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
			mat4_set(res, x, y,
				mat4_get(lhs, x, y) - mat4_get(rhs, x, y));
			x++;
		}
		y++;
	}
	return (res);
}

t_mat4_ptr		mat4_scalar(t_mat4 mat, int scalar, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;

	if (!mat || (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(res, x, y,
				mat4_get(mat, x, y) * scalar);
			x++;
		}
		y++;
	}
	return (res);
}

/*
** res[x][y] = lhs x row . rhs y col
*/

static float	mult_step(unsigned char x, unsigned char y,
	t_mat4 lhs, t_mat4 rhs)
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

t_mat4_ptr		mat4_mult(t_mat4 lhs, t_mat4 rhs, t_mat4 res)
{
	unsigned char	x;
	unsigned char	y;

	if (!lhs || !rhs
		|| (!res && !(res = (t_mat4_ptr)malloc(16 * sizeof(float)))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			mat4_set(res, x, y,
				mult_step(x, y, lhs, rhs));
			x++;
		}
		y++;
	}
	return (res);
}