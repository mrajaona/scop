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
# include "vector.h"

typedef struct	s_light
{
	t_vector	position;
	t_vector	color;
	t_vector	ambient;
	t_vector	diffuse;
	t_vector	specular;
}				t_light;

typedef struct	s_arrays
{
	GLuint		vao;
	GLuint		vbo;
}				t_arrays;

typedef struct	s_info
{
	t_mat4		mat_model;
	t_shader	shader;
	t_arrays	arrays;
	size_t		nfaces;
}				t_info;

typedef struct	s_shadow
{
	GLuint		fbo;
	GLuint		map;
	t_shader	shader;
	t_mat4		mat_model;
	t_mat4		mat_view;
	t_mat4		mat_proj;
}				t_shadow;

typedef struct	s_data
{
	GLFWwindow	*window;
	t_mat4		mat_view;
	t_mat4		mat_proj;
	GLuint		textures[N_TEXTURES];
	t_info		model;
	t_shadow	shadow;
	t_light		light;
}				t_data;

#endif
