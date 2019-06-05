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

static int		vertex_shader(t_shader *shader)
{
	const char *vertex_source = R"glsl(
		#version 330 core

		in vec2 texcoord;
		in vec3 position;
		in vec3 normal;

		out vec2 Texcoord;
		out vec3 Normal;
		out vec3 ModelPos;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		void main()
		{
			gl_Position = proj * view * model * vec4(position, 1.0);
			ModelPos = vec3(model * vec4(position, 1.0));
			Normal = mat3(transpose(inverse(model))) * normal;
			Texcoord = texcoord;
		}
	)glsl";

	shader->vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vertex, 1, &vertex_source, NULL);
	glCompileShader(shader->vertex);
	if (!shader_status(shader->vertex))
		return (0);
	glAttachShader(shader->program, shader->vertex);
	return (1);
}

static int		fragment_shader(t_shader *shader)
{
	const char *fragment_source = R"glsl(
		#version 330 core

		in vec2 Texcoord;
		in vec3 Normal;
		in vec3 ModelPos;

		out vec4 outColor;

		uniform sampler2D texScop;

		uniform vec3 viewPos;

		struct Light {
			vec3 position;
			vec3 color;
			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
		};

		uniform Light light;

		struct Material {
			vec3 ambient;
			vec3 diffuse;
			vec3 specular;
			float shininess;
		};

		uniform Material material;

		void main()
		{
			vec4 tex = texture(texScop, Texcoord);

			// ambient
			vec3 ambient = material.ambient * light.ambient * light.color;
			
			// diffuse
			vec3 norm = normalize(Normal);
			vec3 lightDir = normalize(light.position); // directional
			// vec3 lightDir = normalize(light.position - ModelPos); // spot
			float diff = max(dot(norm, lightDir), 0.0);
			vec3 diffuse = diff * material.diffuse * light.diffuse * light.color;
			
			// specular
			vec3 viewDir = normalize(viewPos - ModelPos);
			vec3 reflectDir = reflect(-lightDir, norm);  
			float spec = pow(max(dot(viewDir, reflectDir), 0.0),
			 material.shininess);
			vec3 specular = spec * material.specular * light.specular * light.color;  
				
			vec3 result = ambient + diffuse + specular;
			outColor = vec4(result, 1.0);
			// outColor = tex * vec4(result, 1.0);
		}

	)glsl";

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
	shader->program = glCreateProgram();
	if (!vertex_shader(shader))
		return (0);
	if (!fragment_shader(shader))
		return (0);
	glBindFragDataLocation(shader->program, 0, "outColor");
	glLinkProgram(shader->program);
	glUseProgram(shader->program);
	return (1);
}
