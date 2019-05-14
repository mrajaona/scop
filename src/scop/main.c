#include "main.h"

int	main(void)
{
	t_data	data;

	init(&data);

	set_scene(&data);
	set_cube(&(data.model));
	set_floor(&(data.floor));
	show(&data);
	data_exit(&data, 0);
}
