#include"color_object.h"

color_obj::color_obj() {}
color_obj::color_obj(const color_obj& other) {
	delete[] vertices;
	delete[] colors;
	this->vertex_count = other.vertex_count;
	this->vertices = new glm::vec3[vertex_count];
	this->colors = new glm::vec4[vertex_count];
	for (int i = 0; i < vertex_count; i++) {
		this->colors[i] = other.colors[i];
		this->vertices[i] = other.vertices[i];
	}
}
color_obj& color_obj::operator=(const color_obj& rhs) {
	if (this != &rhs) {
		if (rhs.vertex_count != vertex_count) {
			delete[] vertices;
			delete[] colors;
			vertex_count = 0;
			colors = nullptr;
			vertices = new glm::vec3[rhs.vertex_count];
			colors = new glm::vec4[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		for (int i = 0; i < vertex_count; i++) {
			vertices[i] = rhs.vertices[i];
			colors[i] = rhs.colors[i];
		}
	}
	return *this;
}
color_obj::~color_obj() {
	delete[] vertices;
	delete[] colors;
}
void color_obj::enable_vao(GLuint attrib_loc) {	glEnableVertexAttribArray(attrib_loc); }
void color_obj::disable_vao(GLuint attrib_loc) { glDisableVertexAttribArray(attrib_loc); }