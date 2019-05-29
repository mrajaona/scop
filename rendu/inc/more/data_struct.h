/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:25:56 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:25:56 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

# define N_TEXTURES 1

# include "glfw_inc.h"

# include "shader_struct.h"

# include "mat4.h"

typedef struct	s_arrays
{
	GLuint		vao;
	GLuint		vbo;
	GLuint		ibo;
}				t_arrays;

typedef struct	s_info
{
	t_shader	shader;
	t_arrays	arrays;
}				t_info;

typedef struct	s_data
{
	GLFWwindow	*window;
	t_mat4		mat_view;
	t_mat4		mat_proj;
	t_mat4		mat_model;
	GLuint		textures[N_TEXTURES];
	size_t		nfaces;
	t_info		model;
	t_info		light;
}				t_data;

#endif
