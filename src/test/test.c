#include "test.h"

/* set elements */

	void	model_del(t_model *model) // fn
	{
		glDeleteBuffers(1, &(model->ebo));
		glDeleteBuffers(1, &(model->vbo));
		glDeleteVertexArrays(1, &(model->vao));	
	}

	void	model_clr(t_model *model) // fn
	{
		clear_matrix(model->mat);
		model->ebo = 0;
		model->vbo = 0;
		model->vao = 0;
	}

	/* cube */

	/* floor */

/* set scene */

	void	set_view(t_data *scop) // fn
		{
		identity(scop->view);

		t_vector	eye;
		t_vector	target;
		t_vector 	up;

		coord_to_vec(1.2f, 1.2f, 1.2f, eye);
		coord_to_vec(0, 0, 0, target);
		coord_to_vec(0, 0, 1, up);

		lookat(eye, target, up, scop->view);
		
		fprintf(stdout, "\nview");
		mat4_print(scop->view);

		GLint uniView = glGetUniformLocation(scop->shader.program, "view");
		glUniformMatrix4fv(uniView, 1, GL_FALSE, scop->view);
	}

	void	set_proj(t_data *scop) // fn
	{
		identity(scop->proj);

		float		planes[2];
		float		vfov;
		float		ratio;

		// vfov = deg_to_rad(45.0f);
		vfov = deg_to_rad(80.0f);
		ratio = 800.0f / 600.0f;
		planes[NEAR_PLANE] = 1.0f;
		planes[FAR_PLANE] = 10.0f;
		
		perspective(vfov, ratio, planes, scop->proj);

		fprintf(stdout, "\nproj");
		mat4_print(scop->proj);

		GLint uniProj = glGetUniformLocation(scop->shader.program, "proj");
		glUniformMatrix4fv(uniProj, 1, GL_FALSE, scop->proj);
	}

	void		set_scene(t_data *scop) // fn
	{
		set_view(scop);
		set_proj(scop);
	}

/* img loader */

	unsigned char	*load(const char *path, int *width, int *height) // fn
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

	int						load_img(const char *path) // fn
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

/* texture */

	void	bw_checkerboard(void) // fn
	{
		float pixels[] = {
			0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f
		};
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
	}

	void	set_TexParameter(const int loaded) // fn
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

	void	texture_init(GLuint textures[N_TEXTURES], const GLuint shader) // fn
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

/* shader */

	int	shader_status(const GLuint shader) // fn
	{
		GLint status;
		
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status != GL_TRUE)
		{
			fprintf(stderr, "shader init error\n");
			fflush(stderr);
			return (FAILURE);
		}
		return (SUCCESS);
	}

	/*
	** place all the stuff
	*/

	void	shader_del(t_shader *shader)
	{
		if (shader->program)
			glDeleteProgram(shader->program);
		if (shader->fragment)
			glDeleteShader(shader->fragment);
		if (shader->vertex)
			glDeleteShader(shader->vertex);
	}

	int	vertex_shader(t_shader *shader) // fn
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
			return (FAILURE);
		glAttachShader(shader->program, shader->vertex);
		return (SUCCESS);
	}

	/*
	** manage colors and textures
	*/

	int	fragment_shader(t_shader *shader) // fn
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
			return (FAILURE);
		glAttachShader(shader->program, shader->fragment);
		return (SUCCESS);
	}

	void	vertex_attribute_array(const GLuint shaderProgram) // fn
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

	int	shader_init(t_shader *shader) // fn
	{
		shader->program = glCreateProgram();

		if (!vertex_shader(shader))
			return (FAILURE);
		if (!fragment_shader(shader))
			return (FAILURE);

		glBindFragDataLocation(shader->program, 0, "outColor");

		glLinkProgram(shader->program);
		glUseProgram(shader->program);

		vertex_attribute_array(shader->program);
		return (SUCCESS);
	}

/* scop */

	void	scop_exit(t_data *scop, const int status) // fn
	{
		scop_del(scop);
		glfwTerminate();
		exit(status);
	}

	void	scop_del(t_data *scop) // fn
	{
		if (scop->data)
			free(scop->data);
		shader_del(&(scop->shader));
	    glDeleteTextures(N_TEXTURES, scop->textures);
		model_del(&(scop->model));
		model_del(&(scop->floor)); // tuto
	}

	void	scop_clr(t_data *scop) // fn
	{
		unsigned int	i;

		scop->data = NULL;
		scop->shader.program = 0;
		scop->shader.vertex = 0;
		scop->shader.fragment = 0;
		clear_matrix(scop->view);
		clear_matrix(scop->proj);
		model_clr(&(scop->model));
		model_clr(&(scop->floor)); // tuto		
		i = 0;
		while (i < N_TEXTURES)
		{
			scop->textures[i] = 0;
			i++;
		}
	}

	void	scop_init(t_data *scop) // fn
	{
		scop_clr(scop);
		if (!shader_init(&(scop->shader)))
			scop_exit(scop, 1);
		texture_init(scop->textures, scop->shader.program);
	}

/* init */

	void	glfw_init() // fn
	{
		GLFWwindow	*window;

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
		
		window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); // Windowed
		// window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); // Fullscreen

		if (!(window))
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
		glfwMakeContextCurrent(window);	
	}

	void	glew_init() // fn
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

	void	init(t_data *scop) // fn
	{
		glfw_init();
		glew_init();
		scop_init(scop);
	}

/* main */

	int	main(void)
	{
		t_data	scop;

		init(&scop);

		set_scene(&scop);
		set_elements();
		show();
		scop_exit(&scop, 0);
	}
