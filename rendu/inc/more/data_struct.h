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

# define N_TEXTURES 2

# include "glfw_inc.h"

# include "shader_struct.h"

# include "mat4.h"

typedef struct	s_arrays
{
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;
}				t_arrays;

typedef struct	s_data
{
	GLFWwindow	*window;
	t_shader	shader;
	GLuint		textures[N_TEXTURES];
	t_mat4		view;
	t_mat4		proj;
	t_mat4		model;
	t_arrays	arrays;
	size_t		nfaces;
}				t_data;

#endif
