#include "render.h"

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
	static GLfloat init_time = 0;
	GLfloat current_time = glfwGetTime();
	GLfloat delta_time = current_time - init_time;
	
	light->translate(glm::vec3(0.0f, -0.001f, 0.0f));

	printf("X pos: %f, Z pos: %f, delta time: %f\n", cos(glm::radians(current_time)), sin(glm::radians(current_time)), delta_time);
	shader_array[0]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", light->get_model_matrix());

	init_time = current_time;
}
