/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:31:42 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:31:43 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

static unsigned char	*load(const char *path, int *width, int *height)
{
	FILE			*fp;
	unsigned char	*image;
	char			magic[8];
	size_t			rd;

	fp = fopen(path, "r");
	if (!fp)
	{
		fprintf(stderr, "Could not open %s\n", path);
		fflush(stderr);
		return (NULL);
	}
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
	if (rd >= 2 && !strncmp(magic, BMP_MAGIC, 2))
	{
		image = load_bmp(fp, width, height);
		// image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);
	}
	else if (rd >= 8 && !strncmp(magic, PNG_MAGIC, 8))
	{
		// image = load_png();
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);
	}
	else if (rd >= 3 && !strncmp(magic, JPG_MAGIC, 3))
	{
		// image = load_jpg();
		image = SOIL_load_image(path, width, height, 0, SOIL_LOAD_RGB);
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
