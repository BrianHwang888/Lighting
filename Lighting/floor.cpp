#include "floor.h"

Floor::Floor() {
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
Floor::Floor(const char* file) {
	read_file(file);
}
Floor::Floor(const Floor& other) {
	this->render_object::render_object(other);
	this->colors = new glm::vec4[vertex_count];
	for (int i = 0; i < vertex_count; i++)
		colors[i] = other.colors[i];
}
void Floor::gen_buffer(GLuint program) {
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
void Floor::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}
void Floor::read_file(const char* file) {
	FILE* fp;
	errno_t errno;
	float x, y, z;
	int vert_points, index = 0;

	errno = fopen_s(&fp, file, "r");
	if (errno ^ 0) {
		fprintf(stderr, "Failed to read file: %s\n", file);
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d", &vertex_count);
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	for (int poly = 0; poly < vertex_count; poly++) {
		if (fscanf_s(fp, "%d", &vert_points) && vert_points == 3) {
			for (int i = 0; i < 3; i++) {

				fscanf_s(fp, "%f", &x);
				fscanf_s(fp, "%f", &y);
				fscanf_s(fp, "%f", &z);

				vertices[index] = glm::vec3(x, y, z);
				colors[index] = glm::vec4(0.25f, 0.25f, 0.25f, 0.65f);
				index++;
			}
		}
		else {
			perror("Invalid data format in file\n");
			system("pause");
			exit(EXIT_FAILURE);
		}
	}
}
Floor& Floor::operator=(const Floor& rhs) {
	if (this != &rhs) {
		if (rhs.vertex_count != vertex_count) {
			delete[] vertices;
			delete[] colors;
			vertex_count = 0;
			vertices = nullptr;
			colors = nullptr;
			vertices = new glm::vec3[rhs.vertex_count];
			colors = new glm::vec4[rhs.vertex_count];
			vertex_count = rhs.vertex_count;
		}
		for (int i = 0; i < vertex_count; i++) {
			vertices[i] = rhs.vertices[i];
			colors[i] = rhs.colors[i];
		}
	}
	return *this;
}