/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.shader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:34:26 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:34:26 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model_shader.h"

static char		*load_shader_err(FILE *fp)
{
	fclose(fp);
	return (NULL);
}

static char		*load_shader(const char *path)
{
	char	*content;
	FILE	*fp;
	long	size;

	fp = fopen(path, "r");
	if (!fp)
		return (NULL);
	fseek(fp, 0L, SEEK_END);
	size = ftell(fp);
	if (size < 0)
		return (load_shader_err(fp));
	rewind(fp);
	if (!(content = (char *)malloc(size + 1)))
		return (load_shader_err(fp));
	if (!fread(content, size, 1, fp))
	{
		free(content);
		return (load_shader_err(fp));
	}
	content[size] = '\0';
	fclose(fp);
	return (content);
}

static int		vertex_shader(t_shader *shader, const char *source)
{
	const char *const	vertex_source = source;

	if (!vertex_source)
		return (0);
	shader->vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vertex, 1, &vertex_source, NULL);
	glCompileShader(shader->vertex);
	if (!shader_status(shader->vertex))
		return (0);
	glAttachShader(shader->program, shader->vertex);
	return (1);
}

static int		fragment_shader(t_shader *shader, const char *source)
{
	const char *const	fragment_source = source;

	if (!fragment_source)
		return (0);
	shader->fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragment, 1, &fragment_source, NULL);
	glCompileShader(shader->fragment);
	if (!shader_status(shader->fragment))
		return (0);
	glAttachShader(shader->program, shader->fragment);
	return (1);
}

int				model_shader_init(t_shader *shader)
{
	char	*shader_source;
	int		res;

	shader->program = glCreateProgram();
	if (!(shader_source = load_shader("src/model/vertex.shader")))
		return (0);
	res = vertex_shader(shader, shader_source);
	free(shader_source);
	if (!res)
		return (0);
	if (!(shader_source = load_shader("src/model/fragment.shader")))
		return (0);
	res = fragment_shader(shader, shader_source);
	free(shader_source);
	if (!res)
		return (0);
	glBindFragDataLocation(shader->program, 0, "outColor");
	glLinkProgram(shader->program);
	glUseProgram(shader->program);
	return (1);
}
