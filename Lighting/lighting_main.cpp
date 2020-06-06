#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"camera.h"
#include"shader.h"
#include"render.h"
#include"init.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod);
void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos);

camera* main_camera;

int main(void) {
	glfwInit();
	printf("OpenGL version supported %s\n", glfwGetVersionString());

	/*----- Window Initialization -----*/
	init_window(3);
	
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Lighting", NULL, NULL);
	if (window == NULL) {
		perror("Failed to create window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	glfwSetKeyCallback(window, keyboard_input_callback);

	glfwSetCursorPosCallback(window, mouse_input_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		perror("Failed to initialize GLAD\n");
		exit(EXIT_FAILURE);
	}

	/*----- Shader Initialization -----*/
	Shader basic_program("basic_vertex.glsl", "basic_fragment.glsl");
	Shader lighting_program("lighting_vertex.glsl", "lighting_fragment.glsl");
	Shader* shader_array[2] = { &basic_program, &lighting_program };

	basic_program.link();
	lighting_program.link();
	
	main_camera = init_main_camera();

	render_object** rendering_object_array = init_rendering_obj();
	init(shader_array, rendering_object_array);
	while (!glfwWindowShouldClose(window)) {

		render(shader_array, rendering_object_array);

		glfwSwapBuffers(window);
		glfwPollEvents();
	
	}

	glfwTerminate();
	return 0;
}

void init_window(int option) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, option);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, option);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod) {
	static GLfloat init_time = 0;
	GLfloat delta_time = 0;
	GLfloat current_time = glfwGetTime();
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	delta_time = current_time - init_time;
	init_time = current_time;
	main_camera->process_input(window, key, action, mod, delta_time);
}
void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos) {
	static double last_x = WINDOW_WIDTH / 2;
	static double last_y = WINDOW_HEIGHT / 2;

	double x_offset = x_pos - last_x;
	double y_offset = last_y - y_pos;

	last_x = x_pos;
	last_y = y_pos;
	main_camera->process_mouse(x_offset, y_offset);
}