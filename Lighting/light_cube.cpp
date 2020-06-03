#include"light_cube.h"

light_cube::light_cube() {
	cube();
	cube_light = new light(position, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

}
light_cube::light_cube(const light_cube& other) {
	cube::cube(other);

}
light_cube::~light_cube() {}
void light_cube::gen_buffer(GLuint program) {
	cube::gen_buffer(program);

}
light_cube& light_cube::operator=(const light_cube& rhs) {
	if (this != &rhs) {
		cube::operator=(rhs);
		

	}
	return *this;
}