#include "tuto.h"

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

void	set_TexParameter()
{
	/*
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	*/
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}

void	tex(GLuint textures[N_TEXTURES], t_data *scop)
{
	glGenTextures(N_TEXTURES, textures);

	// Load texture
	// bw_checkerboard(scop);

	// CAT
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	load_img("sample.png", scop);
	glUniform1i(glGetUniformLocation(scop->shaderProgram, "texKitten"), 0);
	set_TexParameter();

	// DOG
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	load_img("sample2.png", scop);
	glUniform1i(glGetUniformLocation(scop->shaderProgram, "texPuppy"), 1);
	set_TexParameter();
}