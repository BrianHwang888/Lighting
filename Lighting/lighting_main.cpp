#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shader.h"
#include"keyboard.h"
#include"mouse.h"
#include"render.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void main(void) {
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
	
	keyboard main_keyboard;
	glfwSetKeyCallback(window, main_keyboard.keyboard_input_callback);

	mouse main_mouse(WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetCursorPosCallback(window, main_mouse.mouse_input_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		perror("Failed to initialize GLAD\n");
		exit(EXIT_FAILURE);
	}

	/*----- Shader Initialization -----*/
	Shader lighting_program("basic_vertex.glsl", "basic_fragment.glsl");
	Shader* shader_array[1] = { &lighting_program };

	lighting_program.link();

	while (!glfwWindowShouldClose(window)) {

		render(shader_array);

		glfwSwapBuffers(window);
		glfwPollEvents();
	
	}

	glfwTerminate();
}

void init_window(int option) {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, option);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, option);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
