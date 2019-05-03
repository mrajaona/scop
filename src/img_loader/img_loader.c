#include "img_loader.h"

int	load_img(const char *path)
{
	// SOIL
	int				width;
	int				height;
	unsigned char	*image;

	// unsigned char *SOIL_load_image(const char *filename, int *width, int *height, int *channels, int force_channels)
	image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	if (!image)
	{
		fprintf(stderr, "failed to load image\n");
		fflush(stderr);
		return (0);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	return (1);
}
