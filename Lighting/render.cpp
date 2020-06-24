#include "render.h"

#define RADIAN 57.3f

/*----- shader_array[0] = basic_program; shader_array[1] = lighting_program*/

void render(Shader** shader_array, render_object** render_object_array) {
	light_cube* main_light = (light_cube*)render_object_array[2];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	shader_array[0]->use();
	display(shader_array, 0);
	for (int i = 1; i < NUM_STATIC_OBJECTS; i++) {
		render_object_array[i]->draw();
	}
	display_cube(shader_array, main_light);
	main_light->draw();

	int shininess = 32;
	shader_array[1]->use();
	display(shader_array, 1);
	printf("%f, %f, %f\n", main_light->model->get_position().x, main_light->model->get_position().y, main_light->model->get_position().z);
	shader_array[1]->set_uniform_vec3("light_color", glm::vec3(main_light->cube_light->color));
	shader_array[1]->set_uniform_vec3("light_pos", main_light->model->get_position());
	shader_array[1]->set_uniform_vec3("viewer_pos", main_camera->get_position());
	shader_array[1]->set_uniform_int("light_type", main_light->cube_light->type.light_type);
	shader_array[1]->set_uniform_float("ambient_strength", main_light->cube_light->ambient_strength);
	shader_array[1]->set_uniform_float("specular_strength", main_light->cube_light->specular_strength);
	shader_array[1]->set_uniform_int("shininess", shininess);

	render_object_array[0]->draw();
}

void display(Shader** shader_array, int index) {
	glm::mat4 model_matrix;

	shader_array[index]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[index]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[index]->set_uniform_mat4("model", model_matrix);

}

void display_cube(Shader** shader_array, light_cube* light) {
	GLfloat time = glfwGetTime();
	glm::vec3 displacement = light->model->get_velocity() * 0.01f;

	displacement.x *= -sin(glm::radians(time * RADIAN));
	displacement.y *= -sin(glm::radians(time * RADIAN));
	displacement.z *= -cos(glm::radians(time * RADIAN)); 

	light->model->translate(displacement);
	light->model->set_position(light->model->get_position() + displacement);
	shader_array[0]->set_uniform_mat4("projection", main_camera->get_perspective_matrix());
	shader_array[0]->set_uniform_mat4("view", main_camera->get_view_matrix());
	shader_array[0]->set_uniform_mat4("model", light->model->get_model_matrix());

}
