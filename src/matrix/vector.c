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
