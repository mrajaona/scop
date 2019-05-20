#include "scop.h"

void			data_del(t_data *data)
{
	if (data->shader.program)
		glDeleteProgram(data->shader.program);
	if (data->shader.fragment)
		glDeleteShader(data->shader.fragment);
	if (data->shader.vertex)
		glDeleteShader(data->shader.vertex);

    glDeleteTextures(N_TEXTURES, data->textures);

	glDeleteBuffers(1, &(data->model.ebo));
	glDeleteBuffers(1, &(data->model.vbo));
	glDeleteVertexArrays(1, &(data->model.vao));

	glfwTerminate();
}

void			data_exit(t_data *data, const int status)
{
	data_del(data);
	exit(status);
}

void			glfw_init(GLFWwindow **window)
{
	if (!glfwInit())
	{
		fprintf(stderr, "glfw init error\n");
		fflush(stderr);
		exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	*window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
	// window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

	if (!(*window))
	{
		const char *description;
		int code;

		code = glfwGetError(&description);
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		if (description)
			fprintf(stderr, "Code %i: %s\n", code, description);
		fflush(stderr);
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(*window);	
}

void			glew_init(void)
{
	glewExperimental = GL_TRUE;
	int err;
	if ((err = glewInit()) != GLEW_OK)
	{
		fprintf(stderr, "glew init error\n%s\n", glewGetErrorString(err));
		fflush(stderr);
		exit(1);
	}
}

/*
** link points in order
*/

void			ebo(GLuint *ebo)
{
	const GLuint	elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	glGenBuffers(1, ebo); // generate
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo); // make active
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
}

void			vao(GLuint *vao)
{
	glGenVertexArrays(1, vao); // generate
	glBindVertexArray(*vao); // make active
}

/*
** place all points in space
** pos		color	tex
** x y z	r g b	u v
*/
void			vbo(GLuint *vbo)
{
	const float	vertices[] = {

		// cube

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		+0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		+0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, +0.5f, +0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, +0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		// floor

		-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		+1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		+1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		+1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, +1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
	};

	glGenBuffers(1, vbo); // Generate 1 buffer
	glBindBuffer(GL_ARRAY_BUFFER, *vbo); // make active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy the vertex data
}

void			data_clr(t_data *data)
{
	unsigned int	i;

	data->shader.program = 0;
	data->shader.vertex = 0;
	data->shader.fragment = 0;

	mat4_clr(data->view);
	mat4_clr(data->proj);

	mat4_clr(data->model.mat);
	data->model.ebo = 0;
	data->model.vbo = 0;
	data->model.vao = 0;

	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = 0;
		i++;
	}
}

int				shader_status(const GLuint shader)
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

int				vertex_shader(t_shader *shader)
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

int				fragment_shader(t_shader *shader)
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
				texture(texPuppy, Texcoord), 0.5);
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

void			vertex_attribute_array(const GLuint shaderProgram)
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

void			bw_checkerboard(void)
{
	float pixels[] = {
		0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
}

unsigned char	*load(const char *path, int *width, int *height)
{
	FILE			*fp;
	unsigned char	*image;
	char			magic[8];

	fp = fopen(path, "r");
	if (!fp)
	{
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (NULL);
	}

	size_t	rd;
	rd = fread(magic, 1, 8, fp);
	if (!rd)
	{
		fprintf(stderr, "Could not read %s\n", path);
		fflush(stderr);
		fclose(fp);
		return (NULL);
	}

	errno = 0;
	rewind(fp);
	if (errno)
	{
		fclose(fp);
		return (NULL);
	}

	// check format
	if (rd >= 2 && !strncmp(magic, BMP_MAGIC, 2))
	{
		fprintf(stdout, "BMP\n");										// tmp
		fflush(stdout);													// tmp
		// image = load_bmp_img(fp, width, height);
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);	// tmp // floating point exception
	}
	else if (rd >= 8 && !strncmp(magic, PNG_MAGIC, 8))
	{
		fprintf(stdout, "PNG\n");										// tmp
		fflush(stdout);													// tmp
		// image = load_png_image();
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);	// tmp
	}
	else if (rd >= 3 && !strncmp(magic, JPG_MAGIC, 3))
	{
		fprintf(stdout, "JPG\n");										// tmp
		fflush(stdout);													// tmp
		// image = load_jpg_image();
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);	// tmp
	}
	else
	{
		fprintf(stderr, "File format not supported\n");
		fflush(stderr);
		image = NULL;
	}

	fclose(fp);
	return (image);
}

int				load_img(const char *path)
{
	// SOIL
	int				width;
	int				height;
	unsigned char	*image;

	image = load(path, &width, &height);
	if (!image)
	{
		fprintf(stderr, "Failed to load image\n");
		fflush(stderr);
		return (0);
	}
	fflush(stderr);
	glTexImage2D(GL_TEXTURE_2D, 0, TEX_FORMAT, width, height,
		0, TEX_FORMAT, GL_UNSIGNED_BYTE, image);
	free(image);
	return (1);
}

void			set_TexParameter(const int loaded)
{
	if (!loaded)
	{
		bw_checkerboard();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	else
	{
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
}

void			texture_init(GLuint textures[N_TEXTURES], const GLuint shader)
{
	int	success;

	glGenTextures(N_TEXTURES, textures);

	// CAT
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	success = load_img("textures/sample.png");
	glUniform1i(glGetUniformLocation(shader, "texKitten"), 0);
	set_TexParameter(success);

	// DOG
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	success = load_img("textures/sample2.png");
	// success = load_img("textures/marbles.bmp");
	glUniform1i(glGetUniformLocation(shader, "texPuppy"), 1);
	set_TexParameter(success);
}

void 			set_model(t_data *data)
{
	identity(data->model.mat);

	fprintf(stdout, "\nmodel");
	mat4_print(data->model.mat);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, data->model.mat);
}

// The camera in OpenGL cannot move and is defined
// to be located at (0,0,0) facing the negative Z direction
void			set_view(t_data *data)
	{
	identity(data->view);

	t_vector	eye;
	t_vector	target;
	t_vector 	up;

	// example
	coord_to_vec(1.2f, 1.2f, 1.2f, eye);
	coord_to_vec(0, 0, 0, target);
	coord_to_vec(0, 0, 1, up);

	lookat(eye, target, up, data->view);
	
	fprintf(stdout, "\nview");
	mat4_print(data->view);

	GLint uniView = glGetUniformLocation(data->shader.program, "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, data->view);
}

void			set_proj(t_data *data)
{
	identity(data->proj);

	float		planes[2];
	float		vfov;
	float		ratio;

	// example
	// vfov = deg_to_rad(45.0f);
	vfov = deg_to_rad(80.0f);
	ratio = 800.0f / 600.0f;
	planes[NEAR_PLANE] = 1.0f;
	planes[FAR_PLANE] = 10.0f;

	perspective(vfov, ratio, planes, data->proj);

	fprintf(stdout, "\nproj");
	mat4_print(data->proj);

	GLint uniProj = glGetUniformLocation(data->shader.program, "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, data->proj);
}

void			edit_output(const t_data *data, t_mat4 model)
{
	static int		deg = 0;

	deg = (deg + 1) % 360;
	mat4_rotatez(deg_to_rad((float)deg), model);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);
}

void			stencil(const t_data *data, t_mat4 model)
{
	GLint uniColor = glGetUniformLocation(data->shader.program, "overrideColor");
	glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	// Draw cube
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glEnable(GL_STENCIL_TEST);

	// Draw floor
	glStencilFunc(GL_ALWAYS, 1, 0xFF);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glStencilMask(0xFF);
	glDepthMask(GL_FALSE);
	glClear(GL_STENCIL_BUFFER_BIT);
	
	glDrawArrays(GL_TRIANGLES, 36, 6);

	// Draw reflection

	glStencilFunc(GL_EQUAL, 1, 0xFF);
	glStencilMask(0x00);
	glDepthMask(GL_TRUE);

	t_vector	edit;

	coord_to_vec(1.0f, 1.0f, -1.0f, edit);
	scaling(edit, model);

	coord_to_vec(0.0f, 0.0f, -1.0f, edit);
	translation(edit, model);

	GLint uniModel = glGetUniformLocation(data->shader.program, "model");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, model);

	glUniform3f(uniColor, 0.3f, 0.3f, 0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glUniform3f(uniColor, 1.0f, 1.0f, 1.0f);

	glDisable(GL_STENCIL_TEST);
}

void			show(const t_data *data)
{
	t_mat4	model;

	glEnable(GL_DEPTH_TEST);

	while(!glfwWindowShouldClose(data->window))
	{
		mat4_eq(model, data->model.mat);

		glfwSwapBuffers(data->window);
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		edit_output(data, model);

		stencil(data, model);

		usleep(25000);
	}

	glDisable(GL_DEPTH_TEST);
}

int				main(void)
{
	t_data	data;

	data_clr(&data);

	glfw_init(&(data.window));
	glew_init();

	vbo(&(data.model.vbo));
	vao(&(data.model.vao));
	// ebo(&(data.model.ebo));

	if (!shader_init(&(data.shader)))
		data_exit(&data, 1);
	texture_init(data.textures, data.shader.program);

	set_model(&data);
	set_view(&data);
	set_proj(&data);

	show(&data);
	data_exit(&data, 0);
}
