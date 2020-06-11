#ifndef __COLOR_OBJ_H__
#define __COLOR_OBJ_H__

#include"render_object.h"

class color_obj : public render_object {
public:
	color_obj();
	color_obj(const color_obj& other);
	color_obj& operator=(const color_obj& rhs);
	
	void gen_buffer(GLuint program);

protected:
	glm::vec4* colors;

};

#endif // !__COLOR_OBJ_H__

