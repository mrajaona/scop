#include "bmp_img_loader.h"

// size_t	fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);

static void				read_header(t_bmp_header *header, FILE *ptr)
{
	fread(&(header->type), 2, 1, ptr);
	fread(&(header->size), 4, 1, ptr);
	fread(&(header->reserved1), 2, 1, ptr);
	fread(&(header->reserved2), 2, 1, ptr);
	fread(&(header->offset), 4, 1, ptr);
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
