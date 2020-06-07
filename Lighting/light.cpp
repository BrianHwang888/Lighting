#include "light.h"

light::light() {}
light::light(glm::vec3 light_pos, glm::vec4 light_color) : position(light_pos), color(light_color) {
	ambient_strength = 0.1f;
	specular_strength = 0.5f;
	type.light_type = 2;
}
light::light(const light& other) {
	type.light_type = other.get_type();
	color = other.get_light_color();
	position = other.get_light_position();
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
void light::set_color(glm::vec4 light_color) { color = light_color; };
glm::vec3 light::get_light_position() const { return position; }
glm::vec4 light::get_light_color() const { return color; }
int light::get_type() const { return type.light_type; }
void light::set_as_ambient(float strength) { 
	type.light_type = 0;
	ambient_strength = strength; 
}
void light::set_as_diffuse(float amb_strenght, float diff_strength) { 
	type.light_type = 1;
	ambient_strength = amb_strenght;
}
void light::set_as_specular(float amb_strength, float diff_strength, float spec_strength) {
	type.light_type = 2;
	ambient_strength = amb_strength;
	specular_strength = spec_strength;
}
light& light::operator=(const light& rhs) {
	if (this != &rhs) {
		type.light_type = rhs.get_type();
		color = rhs.get_light_color();
		position = rhs.get_light_position();
		ambient_strength = rhs.ambient_strength;
		specular_strength = rhs.specular_strength;
	}
	return *this;
}
