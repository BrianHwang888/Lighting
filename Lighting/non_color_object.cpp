#include"non_color_object.h"

non_color_obj::non_color_obj() {};
non_color_obj::non_color_obj(const non_color_obj& other) {
	delete[] vertices;
	vertex_count = other.vertex_count;
	for (int i = 0; i < vertex_count; i++)
		vertices[i] = other.vertices[i];
};
non_color_obj& non_color_obj::operator=(const non_color_obj& rhs) {
	if (this != &rhs) {
		if (vertex_count != rhs.vertex_count) {
			vertex_count = 0;
			delete[] vertices;
			vertices = new glm::vec3[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		for (int i = 0; i < vertex_count; i++)
			vertices[i] = rhs.vertices[i];
	}
	return *this;
};
non_color_obj::~non_color_obj() { delete[] vertices; };
void non_color_obj::enable_vao(GLuint attrib_loc) { glEnableVertexAttribArray(attrib_loc); };
void non_color_obj::disable_vao(GLuint attrib_loc) { glDisableVertexAttribArray(attrib_loc); };