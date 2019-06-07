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

static unsigned char	*error(const char *err, const char *info, FILE *fp)
{
	if (fp)
		fclose(fp);
	fprintf(stderr, "%s %s\n", err, info);
	fflush(stderr);
	return (NULL);
}

static unsigned char	*load(const char *path, int *width, int *height)
{
	FILE			*fp;
	unsigned char	*image;
	char			magic[8];
	size_t			rd;

	fp = fopen(path, "r");
	if (!fp)
		return (error("Could not open", path, NULL));
	rd = fread(magic, 1, 8, fp);
	if (!rd)
		return (error("Could not read", path, fp));
	errno = 0;
	rewind(fp);
	if (errno)
	{
		fclose(fp);
		return (NULL);
	}
	if (rd >= 2 && !strncmp(magic, BMP_MAGIC, 2))
		image = load_bmp(fp, width, height);
	else
		return (error("File format not supported,", "please use BMP", fp));
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
