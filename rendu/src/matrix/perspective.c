/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:33:13 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:33:14 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perspective.h"

void	perspective(const float vfov, const float ratio, const float planes[2],
	t_mat4 dest)
{
	const float	near = planes[NEAR_PLANE];
	const float	far = planes[FAR_PLANE];
	const float	htan = tanf(vfov / 2);

	mat4_clr(dest);
	if (near == far || htan == 0.0f || ratio == 0.0f)
		return ;
	mat4_set(dest, 0, 0, htan / ratio);
	mat4_set(dest, 1, 1, htan);
	mat4_set(dest, 2, 2, -1 * (far + near) / (far - near));
	mat4_set(dest, 2, 3, -1);
	mat4_set(dest, 3, 2, (-2 * far * near) / (far - near));
}
