#include"light_cube.h"

light_cube::light_cube() {
	cube();
	cube_light = new light(position, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	normals = new glm::vec3[vertex_count];
	glm::vec3 u, v, normal;
	for (int i = 0; i < vertex_count; i += 3) {
		u = vertices[i + 1] - vertices[i];
		v = vertices[i + 2] - vertices[i];
		normal = glm::normalize(glm::cross(u, v));
		normals[i] = normal;
		normals[i + 1] = normal;
		normals[i + 2] = normal;
	}
}
light_cube::light_cube(const light_cube& other) {
	cube::cube(other);

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
	glBufferSubData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4)), vertex_count * sizeof(glm::vec3), normals);

	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	GLuint vertex_normal = glGetAttribLocation(program, "vNormal");

	enable_vao(vertex_position);
	enable_vao(vertex_color);
	enable_vao(vertex_normal);

	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(vertex_count * sizeof(glm::vec3)));
	glVertexAttribPointer(vertex_normal, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)(vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4))));

}
void light_cube::set_light_color(glm::vec4 light_color) { cube_light->set_color(light_color); }
glm::vec4 light_cube::get_light_color() { return cube_light->get_light_color();  }
light_cube& light_cube::operator=(const light_cube& rhs) {
	if (this != &rhs) {
		cube::operator=(rhs);
		if (rhs.vertex_count != vertex_count) {
			delete[] normals;
			vertex_count = 0;
			normals = nullptr;
			normals = new glm::vec3[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		delete cube_light;
		cube_light = rhs.cube_light;
	}
	return *this;
}