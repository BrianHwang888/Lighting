#include "render.h"

void render(Shader** shader_array, render_object** render_object_array) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	render_object_array[0]->draw();
}