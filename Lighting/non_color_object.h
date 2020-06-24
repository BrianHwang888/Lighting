#ifndef __NON_COLOR_OBJ_H__
#define __NON_COLOR_OBJ_H__

#include"render_object.h"

class non_color_obj : public render_object {
public:
	non_color_obj();
	non_color_obj(const non_color_obj& other);
	non_color_obj& operator=(const non_color_obj& rhs);
	~non_color_obj();

	void enable_vao(GLuint attrib_loc) override;
	void disable_vao(GLuint attrib_loc) override;

protected:
	GLuint VAO;
	GLuint vertex_data;
	
	glm::vec3* vertices;

	int vertex_count;
};

#endif // !__NON_COLOR_OBJ_H__
