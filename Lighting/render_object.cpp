#include "render_object.h"

render_object::render_object() {};

render_object::render_object(const render_object& object) {
	this->vertex_count = object.vertex_count;
	this->vertices = new glm::vec3[vertex_count];
	for (int i = 0; i < vertex_count; i++)
		this->vertices[i] = object.vertices[i];
}
void render_object::enable_vao(GLuint attrib_loc) {
	glEnableVertexAttribArray(attrib_loc);
}
void render_object::disable_vao(GLuint attrib_loc) {
	glDisableVertexAttribArray(attrib_loc);
}
render_object& render_object::operator=(render_object& rhs) {
	if (this != &rhs) {
		if (rhs.vertex_count != vertex_count) {
			delete[] vertices;
			vertex_count = 0;
			vertices = nullptr;
			vertices = new glm::vec3[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		for (int i = 0; i < vertex_count; i++)
			vertices[i] = rhs.vertices[i];
	}
	return *this;
}