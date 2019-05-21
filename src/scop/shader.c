#include "shader.h"

static int		shader_status(const GLuint shader)
{
	GLint status;
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		fprintf(stderr, "shader init error\n");
		fflush(stderr);
		return (0);
	}
	return (1);
}

static int		vertex_shader(t_shader *shader)
{
	const char *vertexSource = R"glsl(
		#version 150 core
		
		in vec2 texcoord;
		in vec3 position;
		in vec3 color;
		
		out vec3 Color;
		out vec2 Texcoord;

		uniform mat4 model;
		uniform mat4 view;
		uniform mat4 proj;

		uniform vec3 overrideColor;
		
		void main()
		{
			Texcoord = texcoord;
			Color = overrideColor * color;
			gl_Position = proj * view * model * vec4(position, 1.0);
		}
	)glsl";
	
	shader->vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shader->vertex, 1, &vertexSource, NULL);
	glCompileShader(shader->vertex);
	if (!shader_status(shader->vertex))
		return (0);
	glAttachShader(shader->program, shader->vertex);
	return (1);
}

static int		fragment_shader(t_shader *shader)
{
	const char *fragmentSource = R"glsl(
		#version 150 core
		
		in vec3 Color;
		in vec2 Texcoord;
		out vec4 outColor;
		
		uniform sampler2D texKitten;
		uniform sampler2D texPuppy;
		
		void main()
		{
			vec4 texColor = mix(texture(texKitten, Texcoord),
				texture(texPuppy, Texcoord), 0.1);
			outColor = vec4(Color, 1.0) * texColor;
		}
	)glsl";

	shader->fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shader->fragment, 1, &fragmentSource, NULL);
	glCompileShader(shader->fragment);
	if (!shader_status(shader->fragment))
		return (0);
	glAttachShader(shader->program, shader->fragment);
	return (1);
}

static void		vertex_attribute_array(const GLuint shaderProgram)
{
	GLint posAttrib;
	GLint colAttrib;
	GLint texAttrib;

	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,
		8 * sizeof(float), 0);
	
	colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
		8 * sizeof(float), (void *)(3 * sizeof(float)));

	texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,
		8 * sizeof(float), (void *)(6 * sizeof(float)));
}

int				shader_init(t_shader *shader)
{
	shader->program = glCreateProgram();

	if (!vertex_shader(shader))
		return (0);
	if (!fragment_shader(shader))
		return (0);

	glBindFragDataLocation(shader->program, 0, "outColor");

	glLinkProgram(shader->program);
	glUseProgram(shader->program);

	vertex_attribute_array(shader->program);
	return (1);
}