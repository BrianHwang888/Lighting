#include"init.h"

void init(Shader** shader_array, render_object** rendering_object_array) {
	
	for (int i = 0; rendering_object_array + i != nullptr; i++) {
		rendering_object_array[i]->gen_buffer(shader_array[0]->ID);
	}
	glClearColor(0.529f, 0.807f, 0.92f, 1.0f);
}
render_object** init_rendering_obj() {
	render_object* rendering_object_array[NUM_OBJECTS];

	rendering_object_array[0] = init_floor();

	return rendering_object_array;
}
Floor* init_floor() {
	return new Floor();
}