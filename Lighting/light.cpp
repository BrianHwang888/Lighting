#include "light.h"

light::light() {}
light::light(glm::vec3 light_pos, glm::vec4 light_color) : position(light_pos), color(light_color) {
	ambient_strength = 0.1f;
	specular_strength = 0.5f;
	type.light_type = 2;
}
light::light(const light& other) {
	type.light_type = other.type.light_type;
	color = other.color;
	position = other.position;
	if (type.light_type == 0) {
		ambient_strength = other.ambient_strength;
		specular_strength = 0.0f;
	}
	else if (type.light_type == 1) {
		ambient_strength = other.ambient_strength;
		specular_strength = 0.0f;
	}
	else if (type.light_type == 3) {
		ambient_strength = other.ambient_strength;
		specular_strength = other.specular_strength;
	}
}
light::~light() {}
light& light::operator=(const light& rhs) {
	if (this != &rhs) {
		type.light_type = rhs.type.light_type;
		color = rhs.color;
		position = rhs.position;
		ambient_strength = rhs.ambient_strength;
		specular_strength = rhs.specular_strength;
	}
	return *this;
}
