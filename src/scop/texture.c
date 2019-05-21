#include "texture.h"

static void		bw_checkerboard(void)
{
	float pixels[] = {
		0.0f, 0.0f, 0.0f,	1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,	0.0f, 0.0f, 0.0f
	};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
}

static void		set_TexParameter(const int loaded)
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
	// success = load_img("textures/sample.png");
	// success = load_img("textures/marbles.bmp");
	success = load_img("textures/new_colormap.bmp");
	glUniform1i(glGetUniformLocation(shader, "texKitten"), 0);
	set_TexParameter(success);

	// DOG
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	// success = load_img("textures/sample2.png");
	success = load_img("textures/drop.bmp");
	glUniform1i(glGetUniformLocation(shader, "texPuppy"), 1);
	set_TexParameter(success);
}
