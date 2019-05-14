#include "mat4.h"

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
