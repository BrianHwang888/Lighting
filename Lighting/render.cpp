#include "render.h"

void render(Shader** shader_array, render_object** render_object_array) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	shader_array[0]->use();
	display(shader_array);
	render_object_array[0]->draw();

}

void display(Shader** shader_array) {

	GLfloat fovy = 45.0f;
	GLfloat aspect = 800.0f / 600.0f;
	GLfloat zNear = 0.5f;
	GLfloat zFar = 15.0f;
	GLfloat angle = 0.0f;

	shader_array[0]->set_uniform_mat4("projection", glm::perspective(fovy, aspect, zNear, zFar));

	shader_array[0]->set_uniform_mat4("model_view", main_camera->get_view_matrix());

}