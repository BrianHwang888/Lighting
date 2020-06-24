#ifndef __MOVEABLE_OBJ_H__
#define __MOVEABLE_OBJ_H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>
#include<glm/gtc/matrix_transform.hpp>

class movable_object{
public:
	void translate(glm::vec3 disposition);
	void rotate(GLfloat angle, glm::vec3 axies);
	void scale(glm::vec3 scale_factor);
	void set_velocity(const glm::vec3 velocity);
	void set_model_matrix(const glm::mat4 model);
	void set_position(const glm::vec3 position);

	glm::vec3 get_position() const;
	glm::vec3 get_velocity() const;
	glm::mat4 get_model_matrix() const;

protected:
	glm::vec3 position;
	glm::mat4 model_matrix;
	glm::vec3 velocity;
};

#endif // !__MOVEABLE_OBJ_H__
