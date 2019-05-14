#include "main.h"

int	main(void)
{
	t_data	data;

	init(&data);

	set_scene(&data);
	// set_cube();
	// set_floor();
	// show();
	data_exit(&data, 0);
}
