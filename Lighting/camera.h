#ifndef __CAMERA_H__
#define __CAMERA_H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

class camera {
public:
	camera();
	void process_input(GLFWwindow* window, int key, int action, int mod, GLfloat time);
	void process_mouse(double x_pos, double y_pos);
	glm::mat4 get_view_matrix();
	void update();

private:
	glm::mat4 view_matrix;
	glm::vec3 camera_position;
	glm::vec3 camera_direction;
	glm::vec3 camera_front;
	glm::vec3 camera_right;
	glm::vec3 camera_up;
	glm::vec3 world_up;

	float yaw;
	float pitch;
	float sensitivity;
	float speed;

};

#endif // !__CAMERA_H__
