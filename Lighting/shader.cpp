#include "shader.h"

char* Shader::read_shader_source(const char* file_path) {
	FILE* fp;
	errno_t err = fopen_s(&fp, file_path, "r");
	long length;
	char* buffer;

	if (fp == NULL) {
		fprintf(stderr, "Failed to read file %s\n", file_path);
		system("pause");
		exit(EXIT_FAILURE);
	}

	printf("Successfully read %s\n", file_path);
	fseek(fp, 0L, SEEK_END);
	length = ftell(fp);

	fseek(fp, 0L, SEEK_SET);
	buffer = new char[length + 1];
	fread(buffer, 1, length, fp);
	buffer[length] = '\0';
	fclose(fp);

	for (int i = 0; i < length; i++) {
		if (!(buffer[i] >= 0 && buffer[i] < 128)) {
			buffer[i] = ' ';
		}
	}

	return buffer;
}
Shader::Shader(const char* vertex_path, const char* fragment_path){
	char* vertex_file, *frag_file;
	GLuint vertex_ID, fragment_ID;
	GLint compiled;

	printf("Attempting to read: %s\n", vertex_path);
	vertex_file = read_shader_source(vertex_path);

	printf("Attempting to read: %s\n", fragment_path);
	frag_file = read_shader_source(fragment_path);

	vertex_ID = glCreateShader(GL_VERTEX_SHADER);
	fragment_ID = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertex_ID, 1, (const GLchar**)&vertex_file, NULL);
	glCompileShader(vertex_ID);

	glGetShaderiv(vertex_ID, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLint log_size;
		char* log_msg;
		fprintf(stderr, "%s failed to compiled\n", vertex_path);
		glGetShaderiv(vertex_ID, GL_INFO_LOG_LENGTH, &log_size);
		log_msg = new char[log_size];
		glGetShaderInfoLog(vertex_ID, log_size, NULL, log_msg);
		fprintf(stderr, "Reason: %s\n", log_msg);
		delete[] log_msg;
		system("pause");
		exit(EXIT_FAILURE);
	}

	glShaderSource(fragment_ID, 1, (const GLchar**)&frag_file, NULL);
	glCompileShader(fragment_ID);

	glGetShaderiv(fragment_ID, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		GLint log_size;
		char* log_msg;
		fprintf(stderr, "%s failed to compiled\n", fragment_path);
		glGetShaderiv(fragment_ID, GL_INFO_LOG_LENGTH, &log_size);
		log_msg = new char[log_size];
		glGetShaderInfoLog(fragment_ID, log_size, NULL, log_msg);
		fprintf(stderr, "Reason: %s\n", log_msg);
		delete[] log_msg;
		system("pause");
		exit(EXIT_FAILURE);
	}

	printf("Successfully compiled %s & %s\n\n", vertex_path, fragment_path);

	delete[] vertex_file;
	delete[] frag_file;

	ID = glCreateProgram();
	if (!(ID ^ 0)) {
		fprintf(stderr, "Failed to create shader program using: %s, %s\n", vertex_path, fragment_path);
		exit(EXIT_FAILURE);
	}
	glAttachShader(ID, vertex_ID);
	glAttachShader(ID, fragment_ID);

}
void Shader::link(){
	GLint linked;
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &linked);
	if (!linked) {
		GLint log_size;
		char* log_msg;
		fprintf(stderr, "Shader program failed to link; ID: %d\n", ID);
		glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &log_size);
		log_msg = new char[log_size];
		glGetProgramInfoLog(ID, log_size, NULL, log_msg);
		perror(log_msg);
		delete[] log_msg;
		system("pause");
		exit(EXIT_FAILURE);
	}
	printf("Successfully linked program ID: %d\n\n", ID);

}
void Shader::use() {
	glUseProgram(ID);
}

/*----- Set Uniform Variables -----*/
void Shader::set_uniform_bool(const char* name, GLboolean &value)const {
	glUniform1i(glGetUniformLocation(ID, name), value);
}
void Shader::set_uniform_int(const char* name, GLint &value) const {
	glUniform1i(glGetUniformLocation(ID, name), value);
}
void Shader::set_uniform_float(const char* name, GLfloat &value)const {
	glUniform1f(glGetUniformLocation(ID, name), value);
}
void Shader::set_uniform_double(const char* name, GLdouble &value)const {
	glUniform1d(glGetUniformLocation(ID, name), value);
}

/*----- Set Uniform Vectors -----*/
void Shader::set_uniform_vec2(const char* name, const glm::vec2 &value) const {
	glUniform2fv(glGetUniformLocation(ID, name), 1, &value[0]);
}
void Shader::set_uniform_vec3(const char* name, const glm::vec3 &value) const {
	glUniform3fv(glGetUniformLocation(ID, name), 1, &value[0]);
}
void Shader::set_uniform_vec4(const char* name, const glm::vec4 &value) const {
	glUniform4fv(glGetUniformLocation(ID, name), 1, &value[0]);
}

/*----- Set Uniform Matrices -----*/
void Shader::set_uniform_mat2(const char* name, const glm::mat2 &value) const {
	glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
}
void Shader::set_uniform_mat3(const char* name, const glm::mat3 &value) const {
	glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
}
void Shader::set_uniform_mat4(const char* name, const glm::mat4 &value) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &value[0][0]);
}