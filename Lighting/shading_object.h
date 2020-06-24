#ifndef __SHADING_OBJ_H__
#define __SHADING_OBJ_H__

#include<glm/glm.hpp>
#include"render_object.h"

class shading_obj : public render_object {
public:
	shading_obj();
	shading_obj(const shading_obj& other);
	shading_obj& operator=(const shading_obj& rhs);
	~shading_obj();

	void enable_vao(GLuint attrib_loc) override;
	void disable_vao(GLuint attrib_loc) override;

protected:
	GLuint VAO;
	GLuint vertex_data;

	glm::vec3* vertices;
	glm::vec4* colors;
	glm::vec3* normals;

	int vertex_count;
};

#endif // !__SHADING_OBJ_H__
