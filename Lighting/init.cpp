#include"init.h"

void init(Shader** shader_array, render_object** rendering_object_array) {
	
	for (int i = 0; i < NUM_RENDERING_OBJECTS; i++) {
		rendering_object_array[i]->gen_buffer(shader_array[0]->ID);
	}
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
}
render_object** init_rendering_obj() {
	render_object** rendering_object_array = new render_object*[NUM_RENDERING_OBJECTS];
	
	rendering_object_array[0] = init_floor();
	rendering_object_array[1] = init_grid();
	rendering_object_array[2] = init_light_cube();
	return rendering_object_array;
}
Floor* init_floor() {
	return new Floor();
}
camera* init_main_camera() {
	return new camera();
}
Axies* init_grid() {
	return new Axies();
}
cube* init_cube() {
	return new cube();
}
light_cube* init_light_cube() {
	return new light_cube();
}