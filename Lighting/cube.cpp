#include "cube.h"

cube::cube() {
	vertex_count = 36;
	vertices = new glm::vec3[vertex_count];
	colors = new glm::vec4[vertex_count];

	//1st face
	vertices[0] = glm::vec3(4.5f, 9.5f, 0.5f);
	vertices[1] = glm::vec3(4.5f, 10.5f, 0.5f);
	vertices[2] = glm::vec3(5.5f, 9.5f, 0.5f);

	vertices[3] = glm::vec3(5.5f, 9.5f, 0.5f);
	vertices[4] = glm::vec3(5.5f, 10.5f, 0.5f);
	vertices[5] = glm::vec3(4.5f, 10.5f, 0.5f);

	//2nd face
	vertices[6] = glm::vec3(5.5f, 9.5f, 0.5f);
	vertices[7] = glm::vec3(5.5f, 10.5f, 0.5f);
	vertices[8] = glm::vec3(5.5f, 9.5f, -0.5f);

	vertices[9] = glm::vec3(5.5f, 9.5f, -0.5f);
	vertices[10] = glm::vec3(5.5f, 10.5f, -0.5f);
	vertices[11] = glm::vec3(5.5f, 10.5f, 0.5f);

	//3rd face
	vertices[12] = glm::vec3(5.5f, 10.5f, 0.5f);
	vertices[13] = glm::vec3(5.5f, 10.5f, -0.5f);
	vertices[14] = glm::vec3(4.5f, 10.5f, -0.5f);

	vertices[15] = glm::vec3(4.5f, 10.5f, -0.5f);
	vertices[16] = glm::vec3(4.5f, 10.5f, 0.5f);
	vertices[17] = glm::vec3(5.5f, 10.5f, 0.5f);

	//4th face
	vertices[18] = glm::vec3(5.5f, 10.5f, -0.5f);
	vertices[19] = glm::vec3(5.5f, 9.5f, -0.5f);
	vertices[20] = glm::vec3(4.5f, 9.5f, -0.5f);

	vertices[21] = glm::vec3(4.5f, 9.5f, -0.5f);
	vertices[22] = glm::vec3(4.5f, 10.5f, -0.5f);
	vertices[23] = glm::vec3(5.5f, 10.5f, -0.5f);

	//5th face
	vertices[24] = glm::vec3(5.5f, 9.5f, 0.5f);
	vertices[25] = glm::vec3(5.5f, 9.5f, -0.5f);
	vertices[26] = glm::vec3(4.5f, 9.5f, -0.5f);

	vertices[27] = glm::vec3(4.5f, 9.5f, -0.5f);
	vertices[28] = glm::vec3(4.5f, 9.5f, 0.5f);
	vertices[29] = glm::vec3(5.5f, 9.5f, 0.5f);

	//6th face
	vertices[30] = glm::vec3(4.5f, 10.5f, -0.5f);
	vertices[31] = glm::vec3(4.5f, 9.5f, -0.5f);
	vertices[32] = glm::vec3(4.5f, 9.5f, 0.5f);

	vertices[33] = glm::vec3(4.5f, 9.5f, 0.5f);
	vertices[34] = glm::vec3(4.5f, 10.5f, 0.5f);
	vertices[35] = glm::vec3(4.5f, 10.5f, -0.5f);

	for (int i = 0; i < vertex_count; i++) 
		colors[i] = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	
	model_matrix = glm::mat4(1.0f);
}
cube::cube(const cube& other) {
	this->render_object::render_object(other);
	this->colors = new glm::vec4[vertex_count];
	for (int i = 0; i < vertex_count; i++)
		this->colors[i] = other.colors[i];

	this->model_matrix = *(new glm::mat4(1.0f));
	this->model_matrix = other.model_matrix;
}
void cube::gen_buffer(GLuint program) {
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
void cube::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}
void cube::read_file(const char* file) {
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
void cube::set_model_matrix(glm::mat4 model){
	model_matrix = model;
}
glm::mat4 cube::get_model_matrix() {
	return model_matrix;
}
cube& cube::operator=(const cube& rhs) {
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
			colors[i] = rhs.colors[i];
			vertices[i] = rhs.vertices[i];
		}
		model_matrix = rhs.model_matrix;
	}
	return *this;
}