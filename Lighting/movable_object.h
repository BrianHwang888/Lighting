#ifndef __MOVEABLE_OBJ_H__
#define __MOVEABLE_OBJ_H__

#include<glm/gtc/matrix_transform.hpp>
#include "render_object.h"

class movable_object: public render_object{
public:
	void translate(glm::vec3 disposition);
	void rotate(GLfloat angle, glm::vec3 axies);
	void scale(glm::vec3 scale_factor);

protected:
	glm::mat4 model_matrix;
};

#endif // !__MOVEABLE_OBJ_H__
