#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shader.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init_window(int option);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

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
	glfwSetKeyCallback(window, keyboard_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		perror("Failed to initialize GLAD\n");
		exit(EXIT_FAILURE);
	}

	/*----- Shader Initialization -----*/
	Shader lighting_program("vertex_shader.glsl", "fragment_shader.glsl");

	lighting_program.link();

	while (!glfwWindowShouldClose(window)) {

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
void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}