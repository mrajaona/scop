#include "main.h"

int	main(void)
{
	t_data	data;

	init(&data);

	show(&data);
	data_exit(&data, 0);
}
