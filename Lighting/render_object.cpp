#include "render_object.h"

render_object::render_object() {};

void render_object::enable_vao(GLuint attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
}
void render_object::disable_vao(GLuint attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}