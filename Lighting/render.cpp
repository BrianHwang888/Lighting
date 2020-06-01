#include "render.h"

#define RADIAN 57.3f

void render(Shader** shader_array, render_object** render_object_array) {
	cube* main_light = (cube*)render_object_array[2];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	shader_array[0]->use();
	display(shader_array);
	for (int i = 0; i < NUM_STATIC_OBJECTS; i++) {
		render_object_array[i]->draw();
	}

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
	printf("x: %f, z: %f, time: %f\n", sin(glm::radians(time)), -cos(glm::radians(time)), time);
	shader_array[0]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", light->get_model_matrix());

}
