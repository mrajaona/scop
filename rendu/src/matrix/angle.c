/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:32:05 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:32:06 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "angle.h"

float	deg_to_rad(const float angle)
{
	return (angle * (M_PI / 180.0));
}

float	rad_to_deg(const float angle)
{
	return (angle * (180.0 / M_PI));
}
