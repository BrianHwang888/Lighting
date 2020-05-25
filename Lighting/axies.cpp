#include"axies.h"

Axies::Axies() {
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
void Axies::gen_buffer(GLuint program) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertex_data);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_data);
	glBufferData(GL_ARRAY_BUFFER, vertex_count * (sizeof(glm::vec3) + sizeof(glm::vec4)), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec3) * vertex_count, vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertex_count, vertex_count * sizeof(glm::vec4), colors);

	GLuint vertex_position = glGetAttribLocation(program, "vPosition");
	GLuint vertex_color = glGetAttribLocation(program, "vColor");

	enable_vao(vertex_position);
	enable_vao(vertex_color);

	glVertexAttribPointer(vertex_position, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void*)0);
	glVertexAttribPointer(vertex_color, 4, GL_FLOAT, GL_FALSE, sizeof(glm::vec4), (void*)(sizeof(glm::vec3) * vertex_count));
}
void Axies::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINES, 0, vertex_count);
}
void Axies::read_file(const char* file) {
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