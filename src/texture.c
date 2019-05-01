#include "tuto.h"

static void	gl_status(t_data *scop)
{
	GLenum err;

	if ((err = glGetError()) != GL_NO_ERROR)
	{
		fprintf(stderr, "glTexImage2D fail %#x\n", err);
		fflush(stderr);
		ft_exit(scop, 1);
	}
}

static void	load_img(const char *path, t_data *scop)
{
	// SOIL
	int				width;
	int				height;
	unsigned char	*image;

	image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	if (!image)
	{
		fprintf(stderr, "failed to load image\n");
		fflush(stderr);
		ft_exit(scop, 1);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	gl_status(scop);
	SOIL_free_image_data(image);
}

/*
static void	bw_checkerboard(t_data *scop)
{
	float pixels[] = {
		0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
	gl_status(scop);	
}
*/

void	tex(GLuint *tex, t_data *scop)
{
	glGenTextures(1, tex);
	glBindTexture(GL_TEXTURE_2D, *tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	/*
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	*/

	// Load texture
	// bw_checkerboard(scop);
	load_img("sample.png", scop);
}