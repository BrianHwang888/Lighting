#ifndef __MOVEABLE_OBJ_H__
#define __MOVEABLE_OBJ_H__

#include<glm/gtc/matrix_transform.hpp>
#include "color_object.h"

class movable_object: public color_obj{
public:
	void translate(glm::vec3 disposition);
	void rotate(GLfloat angle, glm::vec3 axies);
	void scale(glm::vec3 scale_factor);
	void set_velocity(glm::vec3 velocity);
	void set_model_matrix(glm::mat4 model);
	
	glm::vec3 get_position();
	glm::vec3 get_velocity();
	glm::mat4 get_model_matrix();

protected:
	glm::vec3 position;
	glm::mat4 model_matrix;
	glm::vec3 velocity;
};

#endif // !__MOVEABLE_OBJ_H__
