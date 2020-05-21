#include "floor.h"

floor::floor() {
	vertex_count = 6;
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	vertices[0] = glm::vec3(5.0f, 0.0f, 8.0f);
	vertices[1] = glm::vec3(-5.0f, 0.0f, 8.0f);
	vertices[2] = glm::vec3(-5.0f, 0.0f, -4.0f);

	vertices[3] = glm::vec3(-5.0f, 0.0f, -4.0f);
	vertices[4] = glm::vec3(5.0f, 0.0f, -4.0f);
	vertices[5] = glm::vec3(5.0f, 0.0f, 8.0f);

	for (int i = 0; i < vertex_count; i++)
		colors[i] = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
}
void floor::gen_buffer(GLuint program) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertex_data);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_data);

	glBufferData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(glm::vec3), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, vertex_count * sizeof(glm::vec3), vertex_count * sizeof(glm::vec4), colors);
	
	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	GLuint vertex_color = glGetAttribLocation(program, "vColor");
	
	enable_vao(vertex_position);
	enable_vao(vertex_color);

	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(vertex_count * sizeof(glm::vec3)));
}
void floor::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}