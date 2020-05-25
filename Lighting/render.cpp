#include "render.h"

void render(Shader** shader_array, render_object** render_object_array) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	shader_array[0]->use();
	display(shader_array);
	for (int i = 0; i < NUM_OBJECTS; i++) {
		render_object_array[i]->draw();
	}

}

void display(Shader** shader_array) {
	static GLfloat init_time = 0;
	GLfloat current_time = glfwGetTime();
	GLfloat delta_time = current_time - init_time;
	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;
	glm::mat4 model_matrix;

	shader_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());

	//model_matrix = glm::translate(model_matrix, glm::vec3(sin(glm::radians(delta_time)), 10.0f, -sin(glm::radians(delta_time))));
	shader_array[0]->set_uniform_mat4("model", model_matrix);

	init_time = current_time;

}