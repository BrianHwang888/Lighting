#ifndef __SHADER_H__
#define __SHADER_H__

#include<stdio.h>
#include<stdlib.h>
#include<glad/glad.h>

class Shader {
	public:
		GLuint ID;
		Shader(const char* vertex_path, const char* fragment_path);
		void link();
		void use();

	private:
		char* read_shader_source(const char* file_path);
};

#endif // !__SHADER_H__
