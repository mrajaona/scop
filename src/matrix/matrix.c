#include "matrix.h"

void	mat4_print(const t_mat4 mat)
{
	fprintf(stdout, "\n% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 0),
		mat4_get(mat, 1, 0),
		mat4_get(mat, 2, 0),
		mat4_get(mat, 3, 0)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 1),
		mat4_get(mat, 1, 1),
		mat4_get(mat, 2, 1),
		mat4_get(mat, 3, 1)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 2),
		mat4_get(mat, 1, 2),
		mat4_get(mat, 2, 2),
		mat4_get(mat, 3, 2)
		);
	fprintf(stdout, "% .2f % .2f % .2f % .2f\n",
		mat4_get(mat, 0, 3),
		mat4_get(mat, 1, 3),
		mat4_get(mat, 2, 3),
		mat4_get(mat, 3, 3)
		);
	fflush(stdout);
}

void		mat4_set(t_mat4 mat, const unsigned char x, const unsigned char y,
	const float value)
{
	if (x >= 4 || y >= 4)
		return ;
	mat[y + (4 * x)] = value;
}

float		mat4_get(const t_mat4 mat, const unsigned char x, const unsigned char y)
{
	if (x >= 4 || y >= 4)
		return (0);
	return (mat[y + (4 * x)]);
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

void		mat4_eq(t_mat4 dst, const t_mat4 src)
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
