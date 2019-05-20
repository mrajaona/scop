#include "img.h"

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
	fflush(stderr);
	glTexImage2D(GL_TEXTURE_2D, 0, TEX_FORMAT, width, height,
		0, TEX_FORMAT, GL_UNSIGNED_BYTE, image);
	free(image);
	return (1);
}