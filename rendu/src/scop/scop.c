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

static void		model(t_data *data, const char *path)
{
	if (!model_shader_init(&(data->model.shader)))
		data_exit(data, 1);
	texture_init(data->textures, data->model.shader.program);

	if (!(load_model(path, data)))
	{
		fprintf(stderr, "Could not load model %s\n", path);
		fflush(stderr);
		exit(1);
	}

	set_model(data);
}

static void		light(t_data *data)
{
	if (!light_shader_init(&(data->light.shader)))
		data_exit(data, 1);
	process_light(data);	
	set_light(data);
}

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

	model(&data, av[1]);
	light(&data);

	set_view(&data);
	set_proj(&data);

	show(&data);
	data_exit(&data, 0);
}
