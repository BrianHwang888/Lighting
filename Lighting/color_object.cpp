#include"color_object.h"

color_obj::color_obj() {}
color_obj::color_obj(const color_obj& other) {
	delete[]colors;
	this->vertex_count = other.vertex_count;
	this->colors = new glm::vec4[vertex_count];
	for (int i = 0; i < vertex_count; i++)
		this->colors[i] = other.colors[i];
}
color_obj& color_obj::operator=(const color_obj& rhs) {
	if (this != &rhs) {
		if (rhs.vertex_count != vertex_count) {
			delete[] colors;
			vertex_count = 0;
			colors = nullptr;
			colors = new glm::vec4[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		for (int i = 0; i < vertex_count; i++)
			colors[i] = rhs.colors[i];
	}
	return *this;
}