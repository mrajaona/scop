#include "img_loader.h"


static unsigned char	*load(const char *path, int *width, int *height)
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

	// clear errno here
	rewind(fp);
	// check errno here

	// check format
	if (rd >= 2 && !strncmp(magic, BMP_MAGIC, rd))
	{
		fprintf(stdout, "BMP\n");										// tmp
		fflush(stdout);													// tmp
		// image = load_bmp_img(fp, width, height);
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);	// tmp
	}
	else if (rd >= 8 && !strncmp(magic, PNG_MAGIC, rd))
	{
		fprintf(stdout, "PNG\n");										// tmp
		fflush(stdout);													// tmp
		// image = load_png_image();
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);	// tmp
	}
	else if (rd >= 3 && !strncmp(magic, JPG_MAGIC, rd))
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

int						load_img(const char *path)
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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
		0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);										// tmp
	return (1);
}
