/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:01 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:02 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_ext.h"

static void		glfw_error(void)
{
	const char	*description;
	int			code;

	code = glfwGetError(&description);
	fprintf(stderr, "ERROR: could not open window with GLFW3\n");
	if (description)
		fprintf(stderr, "Code %i: %s\n", code, description);
	fflush(stderr);
	glfwTerminate();
	exit(1);
}

void			glfw_init(GLFWwindow **window)
{
	if (!glfwInit())
	{
		fprintf(stderr, "glfw init error\n");
		fflush(stderr);
		exit(1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	*window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL",
		NULL, NULL);
	if (!(*window))
		glfw_error();
	glfwMakeContextCurrent(*window);
}
