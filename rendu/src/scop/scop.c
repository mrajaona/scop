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

	printf("%s\n", "loaded");

	vbo(&(data.arrays.vbo));
	printf("%s\n", "ok vbo");
	vao(&(data.arrays.vao));
	printf("%s\n", "ok vao");
	ebo(&(data.arrays.ebo));
	printf("%s\n", "ok ebo");

	if (!shader_init(&(data.shader)))
		data_exit(&data, 1);
	printf("%s\n", "ok shader");
	texture_init(data.textures, data.shader.program);
	printf("%s\n", "ok textures");

	set_model(&data);
	printf("%s\n", "ok model");
	set_view(&data);
	printf("%s\n", "ok view");
	set_proj(&data);
	printf("%s\n", "ok proj");

	show(&data);
	data_exit(&data, 0);
}
