#include "img_bmp.h"

static void				read_header(t_bmp_header *header, FILE *ptr)
{
	fread(&(header->type), 2, 1, ptr);
	fread(&(header->size), 4, 1, ptr);
	fread(&(header->reserved1), 2, 1, ptr);
	fread(&(header->reserved2), 2, 1, ptr);
	fread(&(header->offset), 4, 1, ptr);
	
	// debug
	fprintf(stdout, "\n--- Header\ntype: %c%c\nsize: %u\nr1: %hu\nr2: %hu\noffset: %u\n",
		((char *)(&(header->type)))[0],
		((char *)(&(header->type)))[1],
		header->size,
		header->reserved1,
		header->reserved2,
		header->offset
	);
	fflush(stdout);
	
}

static void				read_info(t_bmp_info *info, FILE *ptr)
{
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
	
	// debug
	fprintf(stdout, "\n--- Info\nsize: %u\nwidth: %i\nheight: %i\nplanes: %hu\nbits: %hu\ncompression: %u\nimagesize: %u\nxresolution: %i\nyresolution: %i\nncolours: %u\nimportantcolours: %u\n",
		info->size,
		info->width,
		info->height,
		info->planes,
		info->bits,
		info->compression,
		info->imagesize,
		info->xresolution,
		info->yresolution,
		info->ncolours,
		info->importantcolours
	);
	fflush(stdout);
	
}

// bgr to rgb
static int				read_pixel(unsigned char *pixel, FILE *ptr,
	t_bmp_info *info)
{
	unsigned char		px;
	const unsigned int	npixels = 1;

	if (fread(pixel, npixels, info->bits / 8, ptr) != info->bits / 8 * npixels)
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

	last = line + line_size;
	pixel = line;
	while (pixel < last)
	{
		if (!read_pixel(pixel, ptr, info))
			return (0);
		pixel += info->bits / 8;
	}	
	return (1);
}

static unsigned char	*read_data(FILE *ptr,
	t_bmp_header *header, t_bmp_info *info)
{
	unsigned char	*image;
	unsigned char	*line;
	int				n;
	size_t			size;

	if (fseek(ptr, header->offset, SEEK_SET) < 0)
		return (NULL);
	size = header->size - header->offset;
	
	if (!(image = (unsigned char *)malloc(size * sizeof(unsigned char))))
		return (NULL);

	line = image + size - (size / info->height);
	size = size / info->height;
	n = 0;
	while (n < info->height && line >= image)
	{
		if (!read_line(ptr, line, size, info))
		{
			free(image);
			return (NULL);
		}
		line -= size;
		n++;
	}
	return (image);
}

/*

static int				read_line(FILE *ptr, unsigned char *line,
	size_t line_size, t_bmp_info *info)
{
	unsigned char	*pixel;
	unsigned char	*last;
	unsigned int	rd;

	last = line + line_size;
	pixel = line;
	while (pixel < line + info->width)
	{
		if (!read_pixel(pixel, ptr, info))
			return (0);
		pixel += info->bits / 8;
	}

	fprintf(stdout, "%p %p %zu\n", pixel, last, last - pixel);
	fflush(stdout);

	while (pixel < last)
	{
		if ((rd = fread(pixel, 1, last - pixel, ptr)) == 0)
			return (0);
		fprintf(stdout, "%u\n", rd);
		pixel += rd;
	}
	if (pixel > last)
	{
		fprintf(stderr, "Got past end of line\n");
		fflush(stderr);
		return (0);
	}

	return (1);
}


*/

unsigned char			*load_bmp(FILE *ptr, int *width, int *height)
{
	t_bmp_header	header;
	t_bmp_info		info;

	read_header(&header, ptr);
	read_info(&info, ptr);
	*width = info.width;
	*height = info.height;
	return (read_data(ptr, &header, &info));
}
