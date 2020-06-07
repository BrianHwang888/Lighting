#include "light.h"

light::light() {}
light::light(glm::vec3 light_pos, glm::vec4 light_color) : position(light_pos), color(light_color) {}
light::~light() {}
void light::set_color(glm::vec4 light_color) { color = light_color; };
glm::vec4 light::get_light_color() { return color; }
