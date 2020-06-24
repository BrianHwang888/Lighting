#ifndef __RENDER_OBJECT__
#define __RENDER_OBJECT__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>
#include<stdio.h>
#include<stddef.h>

class render_object {
public:
	virtual void gen_buffer(GLuint program) = 0;
	virtual void draw() = 0;
	virtual void read_file(const char* file) = 0;
	virtual void enable_vao(GLuint attrib_loc) = 0;
	virtual void disable_vao(GLuint attrib_loc) = 0;

};
#endif // !__RENDER_OBJECT__
