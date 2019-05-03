#include "bmp_img_loader.h"

// size_t	fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);

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

static unsigned char	*read_data(FILE *ptr,
	t_bmp_header *header, t_bmp_info *info)
{
	unsigned char	*image;

	image = NULL;
	(void)ptr; (void)header; (void)info;
	return (image);
}

unsigned char			*load_bmp_img(FILE *ptr, int *width, int *height)
{
	t_bmp_header	header;
	t_bmp_info		info;

	read_header(&header, ptr);
	read_info(&info, ptr);
	*width = info.width;
	*height = info.height;
	return (read_data(ptr, &header, &info));
}