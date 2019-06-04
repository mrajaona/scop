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

void	perspective(t_mat4 dest)
{
	const float vfov = deg_to_rad(VFOV_DEG);
	const float	htan = tanf(vfov / 2);

	if (!dest)
		return ;
	mat4_clr(dest);
	if (P_NEAR == P_FAR || htan == 0.0f || SCREEN_RATIO == 0.0f)
		return ;
	mat4_set(dest, 0, 0, htan / SCREEN_RATIO);
	mat4_set(dest, 1, 1, htan);
	mat4_set(dest, 2, 2, -1 * (P_FAR + P_NEAR) / (P_FAR - P_NEAR));
	mat4_set(dest, 2, 3, -1);
	mat4_set(dest, 3, 2, (-2 * P_FAR * P_NEAR) / (P_FAR - P_NEAR));
}
