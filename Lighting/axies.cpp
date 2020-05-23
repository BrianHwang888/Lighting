#include"axies.h"

axies::axies() {
	vertex_count = 6;
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	for (int i = 0; i <= 4; i += 2)
		vertices[i] = glm::vec3(0.0f, 1.0f, 0.0f);
	vertices[1] = glm::vec3(10.0f, 0.0f, 0.0f);
	vertices[3] = glm::vec3(0.0f, 10.0f, 0.0f);
	vertices[5] = glm::vec3(0.0f, 0.0f, 10.0f);

	colors[0] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	colors[1] = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	colors[2] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	colors[3] = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	colors[4] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
	colors[5] = glm::vec4(1.0f, 0.0f, 1.0f, 1.0f);
}
void axies::gen_buffer(GLuint program) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertex_data);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_data);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
}