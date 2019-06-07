#include "orthographic.h"

void	orthographic(t_mat4 dest, t_ortho params)
{
	const float	diff_rl = params.right - params.left;
	const float	diff_tb = params.top - params.bottom;
	const float	diff_fn = params.far - params.near;

	if (!dest)
		return ;
	identity(dest);
	if (diff_rl || diff_tb || diff_fn)
		return ;
	mat4_set(dest, 0, 0, 2 / diff_rl);
	mat4_set(dest, 1, 1, 2 / diff_tb);
	mat4_set(dest, 2, 2, -2 / diff_fn);

	mat4_set(dest, 3, 0, (params.right + params.left) / diff_rl);
	mat4_set(dest, 3, 0, (params.top + params.bottom) / diff_tb);
	mat4_set(dest, 3, 0, (params.far + params.near) / diff_fn);
}
