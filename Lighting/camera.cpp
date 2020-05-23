#include"camera.h"

camera::camera() {
	yaw = -291.150330f;
	pitch = -44.100040;
	sensitivity = 0.05f;
	speed = 2.5f;
	world_up = glm::vec3(0.0f, 1.0f, 0.0f);

	camera_position = glm::vec3(-0.740888f, 5.304087f, -3.330249f);
	camera_front = glm::vec3(0.259112f, -0.695913f, 0.669751f);

	camera_right = glm::normalize(glm::cross(camera_front, world_up));
	camera_up = glm::normalize(glm::cross(camera_right, camera_front));
	camera_direction = camera_position + camera_front;

	view_matrix = glm::lookAt(camera_position, camera_direction, camera_up);
}
glm::mat4 camera::get_view_matrix() {
	return view_matrix;
}
void camera::update() {
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	
	camera_front = glm::normalize(front);
	camera_right = glm::normalize(glm::cross(camera_front, world_up));
	camera_up = glm::normalize(glm::cross(camera_right, camera_front));
	camera_direction = camera_position + camera_front;

	view_matrix = glm::lookAt(camera_position, camera_direction, camera_up);
}
void camera::process_input(GLFWwindow* window, int key, int action, int mod, GLfloat time) {
	float camera_speed = speed * time;
	if (key == GLFW_KEY_W && (action == GLFW_REPEAT || action == GLFW_PRESS))
		camera_position += (camera_front * camera_speed);

	if (key == GLFW_KEY_A && (action == GLFW_REPEAT || action == GLFW_PRESS))
		camera_position -= (camera_right * camera_speed);

	if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
		camera_position -= (camera_front * camera_speed);

	if (key == GLFW_KEY_D && (action == GLFW_REPEAT || action == GLFW_PRESS))
		camera_position += (camera_right * camera_speed);

	if (key == GLFW_KEY_SPACE && (action == GLFW_REPEAT || action == GLFW_PRESS))
		camera_position += (camera_up * camera_speed);

	//goes to original position
	if (key == GLFW_KEY_O && action == GLFW_PRESS) {
		camera_direction = glm::vec3(0.0f, 0.1f, 0.0f);
		camera_position = glm::vec3(-0.740888f, 5.304087f, -3.330249f);
		camera_front = glm::vec3(0.259112f, -0.695913f, 0.669751f);
		yaw = -291.150330f;
		pitch = -44.100040;
	}

	if (key == GLFW_KEY_O && action == GLFW_PRESS && mod == GLFW_MOD_SHIFT) {
		camera_direction = camera_front + camera_position;
	}

	if (key == GLFW_KEY_P && action == GLFW_PRESS)
		camera_position = glm::vec3(-1.0f, 6.0f, -4.0f);

	update();
}
void camera::process_mouse(double x_offest, double y_offset) {
	x_offest *= sensitivity;
	y_offset *= sensitivity;

	yaw += x_offest;
	pitch += y_offset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	update();
}