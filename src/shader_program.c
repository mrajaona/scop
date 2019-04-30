#include "tuto.h"

static void	shader_status(GLuint shader)
{
	// check success
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE)
	{
		write(2, "shader init error\n", 18); // err
	}
	
	// log
	char buffer[512];
	glGetShaderInfoLog(shader, 512, NULL, buffer);	
}

static void	vertex_shader(GLuint shaderProgram)
{
	const char *vertexSource = R"glsl(
		#version 150 core
		in vec2 position;

		void main()
		{
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


static void	fragment_shader(GLuint shaderProgram)
{
	const char *fragmentSource = R"glsl(
		#version 150 core
		out vec4 outColor;

		void main()
		{
			outColor = vec4(1.0, 1.0, 1.0, 1.0);
		}
	)glsl";
	GLuint fragmentShader;

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	shader_status(fragmentShader);
	glAttachShader(shaderProgram, fragmentShader);
}

static void	vertex_attribute_array(GLuint shaderProgram)
{
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);	
}

void	shader_program()
{
	GLuint	shaderProgram;

	shaderProgram = glCreateProgram();

	vertex_shader(shaderProgram);
	fragment_shader(shaderProgram);

	glBindFragDataLocation(shaderProgram, 0, "outColor");

	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	vertex_attribute_array(shaderProgram);
}
