#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shader.h"
#include"render.h"
#include"init.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod);
void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos);

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
	Shader lighting_program("basic_vertex.glsl", "basic_fragment.glsl");
	Shader* shader_array[1] = { &lighting_program };

	lighting_program.link();
	
	
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
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

}
void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos) {
	static double last_x = WINDOW_WIDTH / 2;
	static double last_y = WINDOW_HEIGHT / 2;

	double x_offset = x_pos - last_x;
	double y_offset = last_y - y_pos;

	last_x = x_pos;
	last_y = y_pos;

}