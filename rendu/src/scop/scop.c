/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:07 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:08 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int				main(void)
{
	t_data	data;

	data_clr(&data);

	glfw_init(&(data.window));
	glew_init();

	load_model("resources/cube.obj", &data);

	if (!shader_init(&(data.shader)))
		data_exit(&data, 1);
	texture_init(data.textures, data.shader.program);

	set_model(&data);
	set_view(&data);
	set_proj(&data);

	show(&data);
	data_exit(&data, 0);
}
