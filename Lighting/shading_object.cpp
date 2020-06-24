#include"shading_object.h"

shading_obj::shading_obj() {};
shading_obj::shading_obj(const shading_obj& other) {
	vertex_count = 0;
	delete[] vertices;
	delete[] colors;
	delete[] normals;

	vertices = new glm::vec3[other.vertex_count];
	colors = new glm::vec4[other.vertex_count];
	normals = new glm::vec3[other.vertex_count];
	vertex_count = other.vertex_count;
};
shading_obj& shading_obj::operator=(const shading_obj& rhs) {
	if (this != &rhs) {
		if (vertex_count != rhs.vertex_count) {
			vertex_count = 0;
			delete[] vertices;
			delete[] colors;
			delete[] normals;
			vertices = new glm::vec3[rhs.vertex_count];
			colors = new glm::vec4[rhs.vertex_count];
			normals = new glm::vec3[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
	}
	return *this;
};
shading_obj::~shading_obj() {
	delete[] vertices;
	delete[] colors;
	delete[] normals;
};
void shading_obj::enable_vao(GLuint attrib_loc) { glEnableVertexAttribArray(attrib_loc); };
void shading_obj::disable_vao(GLuint attrib_loc) { glDisableVertexAttribArray(attrib_loc); };
