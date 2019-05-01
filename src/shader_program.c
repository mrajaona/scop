#include "tuto.h"

static void	shader_status(const GLuint shader)
{
	// check success
	GLint status;
	
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		write(2, "shader init error\n", 18); // err
		exit(1);
	}
	
	// log
	char buffer[512];
	glGetShaderInfoLog(shader, 512, NULL, buffer);	
}

static void	vertex_shader(const GLuint shaderProgram)
{
	const char *vertexSource = R"glsl(
		#version 150 core
		in vec2 position;
		in vec3 color;
		out vec3 Color;
		
		void main()
		{
			Color = color;
			gl_Position = vec4(position, 0.0, 1.0);
		}
	)glsl";
	GLuint vertexShader;
	
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	shader_status(vertexShader);
	glAttachShader(shaderProgram, vertexShader);
}


static void	fragment_shader(const GLuint shaderProgram)
{
	const char *fragmentSource = R"glsl(
		#version 150 core
		in vec3 Color;
		out vec4 outColor;
		
		void main()
		{
			outColor = vec4(Color, 1.0);
		}
	)glsl";
	GLuint fragmentShader;

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	shader_status(fragmentShader);
	glAttachShader(shaderProgram, fragmentShader);
}

static void	vertex_attribute_array(const GLuint shaderProgram)
{
	GLint posAttrib;
	GLint colAttrib;

	posAttrib = glGetAttribLocation(shaderProgram, "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
		5 * sizeof(float), 0);
	
	colAttrib = glGetAttribLocation(shaderProgram, "color");
	glEnableVertexAttribArray(colAttrib);
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
		5 * sizeof(float), (void *)(2 * sizeof(float)));
}

void	shader_program(GLuint *shaderProgram)
{
	*shaderProgram = glCreateProgram();

	vertex_shader(*shaderProgram);
	fragment_shader(*shaderProgram);

	glBindFragDataLocation(*shaderProgram, 0, "outColor");

	glLinkProgram(*shaderProgram);
	glUseProgram(*shaderProgram);

	vertex_attribute_array(*shaderProgram);
}
