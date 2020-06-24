#include"light_cube.h"

light_cube::light_cube() {
	cube();
	cube_light = new light(model->get_position(), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
}
light_cube::light_cube(const light_cube& other) {
	cube::cube(other);
	delete cube_light;
	cube_light = new light(*(other.cube_light));
}
light_cube::~light_cube() {}
void light_cube::gen_buffer(GLuint program) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertex_data);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_data);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(glm::vec3), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, vertex_count * sizeof(glm::vec3), vertex_count * sizeof(glm::vec4), colors);

	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	GLuint vertex_color = glGetAttribLocation(program, "vColor");

	enable_vao(vertex_position);
	enable_vao(vertex_color);

	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(vertex_count * sizeof(glm::vec3)));

}
light_cube& light_cube::operator=(const light_cube& rhs) {
	if (this != &rhs) {
		cube::operator=(rhs);
		delete cube_light;
		cube_light = rhs.cube_light;
	}
	return *this;
}