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
	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;
	glm::mat4 model_matrix;

	shader_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", model_matrix);

}

void display_cube(Shader** shader_array, cube* light) {
	static GLfloat init_time = 0;
	static GLfloat degree = 0;
	GLfloat current_time = glfwGetTime();
	GLfloat delta_time = current_time - init_time;
	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;
	glm::mat4 model_matrix = light->get_model_matrix();

	shader_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", model_matrix);

	init_time = current_time;
	//model_matrix = glm::translate(model_matrix, glm::vec3(cos(glm::radians(degree)), 0.0f, sin(glm::radians(degree))));
	light->set_model_matrix(model_matrix);
	degree++;
	if (degree <= 360.0f) {
		degree = 0.0f;
	}

}