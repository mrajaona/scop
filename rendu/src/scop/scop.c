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

int				main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
	{
		fprintf(stdout, "No model to load\n");
		fflush(stdout);		
		return (0);
	}

	data_clr(&data);

	glfw_init(&(data.window));
	glew_init();

	if (!shader_init(&(data.shader)))
		data_exit(&data, 1);
	texture_init(data.textures, data.shader.program);

	if (!(load_model(av[1], &data)))
	{
		fprintf(stderr, "Could not load model %s\n", av[1]);
		fflush(stderr);
		return (1);
	}

	process_light(&data);	

	set_model(&data);
	set_view(&data);
	set_proj(&data);

	show(&data);
	data_exit(&data, 0);
}
