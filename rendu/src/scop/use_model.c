/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:20:11 by mrajaona          #+#    #+#             */
/*   Updated: 2019/06/07 11:20:11 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_model.h"

void		use_no_model(void)
{
	glBindVertexArray(0);
	glUseProgram(0);
}

void		use_model(const t_info *model)
{
	glBindVertexArray(model->arrays.vao);
	glUseProgram(model->shader.program);
}
