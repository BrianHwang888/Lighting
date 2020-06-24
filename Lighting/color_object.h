#ifndef __COLOR_OBJ_H__
#define __COLOR_OBJ_H__

#include"render_object.h"

class color_obj : public render_object {
public:
	color_obj();
	color_obj(const color_obj& other);
	color_obj& operator=(const color_obj& rhs);
	~color_obj();
	void enable_vao(GLuint attrib_loc) override;
	void disable_vao(GLuint attrib_loc) override;

protected:
	GLuint VAO;
	GLuint vertex_data;
	glm::vec3* vertices;
	glm::vec4* colors;

	int vertex_count;
};

#endif // !__COLOR_OBJ_H__

