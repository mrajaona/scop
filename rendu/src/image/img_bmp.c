/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrajaona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:31:49 by mrajaona          #+#    #+#             */
/*   Updated: 2019/05/24 11:31:51 by mrajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_bmp.h"

static void				read_infos(t_bmp_header *header, t_bmp_info *info,
	FILE *ptr)
{
	fread(&(header->type), 2, 1, ptr);
	fread(&(header->size), 4, 1, ptr);
	fread(&(header->reserved1), 2, 1, ptr);
	fread(&(header->reserved2), 2, 1, ptr);
	fread(&(header->offset), 4, 1, ptr);
	fread(&(info->size), 4, 1, ptr);
	fread(&(info->width), 4, 1, ptr);
	fread(&(info->height), 4, 1, ptr);
	fread(&(info->planes), 2, 1, ptr);
	fread(&(info->bits), 2, 1, ptr);
	fread(&(info->compression), 4, 1, ptr);
	fread(&(info->imagesize), 4, 1, ptr);
	fread(&(info->xresolution), 4, 1, ptr);
	fread(&(info->yresolution), 4, 1, ptr);
	fread(&(info->ncolours), 4, 1, ptr);
	fread(&(info->importantcolours), 4, 1, ptr);
}

/*
** bgr to rgb
*/

static int				read_pixel(unsigned char *pixel, FILE *ptr,
	t_bmp_info *info)
{
	unsigned char		px;
	const unsigned int	npixels = 1;
	const unsigned int	nbytes = info->bits / 8;

	if (fread(pixel, npixels, nbytes, ptr) != nbytes * npixels)
		return (0);
	px = pixel[0];
	pixel[0] = pixel[2];
	pixel[1] = pixel[1];
	pixel[2] = px;
	return (1);
}

static int				read_line(FILE *ptr, unsigned char *line,
	size_t line_size, t_bmp_info *info)
{
	unsigned char	*pixel;
	unsigned char	*last;
	size_t			len;

	len = info->width * info->bits / 8;
	last = line + len;
	pixel = line;
	while (pixel < last)
	{
		if (!read_pixel(pixel, ptr, info))
			return (0);
		pixel += info->bits / 8;
	}
	if (fseek(ptr, line_size - len, SEEK_CUR) < 0)
		return (0);
	return (1);
}

static unsigned char	*read_data(FILE *ptr,
	t_bmp_header *header, t_bmp_info *info)
{
	unsigned char	*image;
	unsigned char	*line;
	int				n;
	size_t			size;
	size_t			line_size;

	size = info->height * info->width * (info->bits / 8);
	if (!(image = (unsigned char *)malloc(size * sizeof(unsigned char))))
		return (NULL);
	line = image + size;
	size = info->width * (info->bits / 8);
	line -= size;
	line_size = (header->size - header->offset) / info->height;
	n = 0;
	while (n < info->height && line >= image)
	{
		if (!read_line(ptr, line, line_size, info))
		{
			free(image);
			return (NULL);
		}
		line -= size;
		n++;
	}
	return (image);
}

unsigned char			*load_bmp(FILE *ptr, int *width, int *height)
{
	t_bmp_header	header;
	t_bmp_info		info;

	read_infos(&header, &info, ptr);
	*width = info.width;
	*height = info.height;
	if (fseek(ptr, header.offset, SEEK_SET) < 0)
		return (NULL);
	return (read_data(ptr, &header, &info));
}
