#include "render.h"

#define RADIAN 57.3f

/*----- shader_array[0] = basic_program; shader_array[1] = lighting_program*/

void render(Shader** shader_array, render_object** render_object_array) {
	cube* main_light = (cube*)render_object_array[2];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	shader_array[0]->use();
	display(shader_array);
	for (int i = 0; i < NUM_STATIC_OBJECTS; i++) {
		render_object_array[i]->draw();
	}

	shader_array[1]->use();
	display_cube(shader_array, main_light);
	main_light->draw();
}

void display(Shader** shader_array) {
	glm::mat4 model_matrix;

	shader_array[0]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", model_matrix);

}

void display_cube(Shader** shader_array, cube* light) {
	GLfloat time = glfwGetTime();
	glm::vec3 displacement = light->get_velocity() * 0.01f;

	displacement.x *= -sin(glm::radians(time * RADIAN));
	displacement.z *= -cos(glm::radians(time * RADIAN));

	light->translate(displacement);
	shader_array[0]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", light->get_model_matrix());

}
void display_light_cube(Shader** shader_array, light_cube* cube) {
	GLfloat time = glfwGetTime();
	glm::vec3 displacement = cube->get_velocity() * 0.01f;

	displacement.x *= -sin(glm::radians(time * RADIAN));
	displacement.z *= -cos(glm::radians(time * RADIAN));

	cube->translate(displacement);
	shader_array[1]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[1]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[1]->set_uniform_mat4("model", cube->get_model_matrix());
	shader_array[1]->set_uniform_vec3("light_color", cube->get_light_color());
}