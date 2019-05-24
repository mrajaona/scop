#include "scop.h"

int				main(void)
{
	t_data	data;

	data_clr(&data);

	glfw_init(&(data.window));
	// glew_init();

	load_model("resources/cube.obj", &data);
	vbo(&(data.arrays.vbo));
	vao(&(data.arrays.vao));
	// ebo(&(data.arrays.ebo));

	if (!shader_init(&(data.shader)))
		data_exit(&data, 1);
	texture_init(data.textures, data.shader.program);


	set_model(&data);
	set_view(&data);
	set_proj(&data);

	show(&data);
	data_exit(&data, 0);
}
