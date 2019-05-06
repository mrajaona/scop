#include "shader.h"

static void	shader_status(const GLuint shader, t_data *scop)
{
	// check success
	GLint status;
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		fprintf(stderr, "shader init error\n");
		fflush(stderr);
		ft_exit(scop, 1);
	}
}

static void	vertex_shader(const GLuint shaderProgram, t_data *scop)
{
	const char *vertexSource = R"glsl(
		#version 150 core
		
		in vec2 texcoord;
		in vec2 position;
		in vec3 color;
		
		out vec3 Color;
		out vec2 Texcoord;
		
		void main()
		{
			Texcoord = texcoord;
			Color = color;
			gl_Position = vec4(position, 0.0, 1.0);
		}
	)glsl";
	
	scop->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(scop->vertexShader, 1, &vertexSource, NULL);
	glCompileShader(scop->vertexShader);
	shader_status(scop->vertexShader, scop);
	glAttachShader(shaderProgram, scop->vertexShader);
}


static void	fragment_shader(const GLuint shaderProgram, t_data *scop)
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
			vec4 colKitten = texture(texKitten, Texcoord);
			vec4 colPuppy = texture(texPuppy, Texcoord);
			outColor = mix(colKitten, colPuppy, 0.5);
		}
	)glsl";

	scop->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(scop->fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(scop->fragmentShader);
	shader_status(scop->fragmentShader, scop);
	glAttachShader(shaderProgram, scop->fragmentShader);
}

static void	vertex_attribute_array(const GLuint shaderProgram)
{
	GLint posAttrib;
	GLint colAttrib;
	GLint texAttrib;

	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), 0);
	
	colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), (void *)(2 * sizeof(float)));

	texAttrib = glGetAttribLocation(shaderProgram, "texcoord");
	glEnableVertexAttribArray(texAttrib);
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,
		7 * sizeof(float), (void *)(5 * sizeof(float)));
}

void	shader_program(GLuint *shaderProgram, t_data *scop)
{
	*shaderProgram = glCreateProgram();

	vertex_shader(*shaderProgram, scop);
	fragment_shader(*shaderProgram, scop);

	glBindFragDataLocation(*shaderProgram, 0, "outColor");

	glLinkProgram(*shaderProgram);
	glUseProgram(*shaderProgram);

	vertex_attribute_array(*shaderProgram);
}
