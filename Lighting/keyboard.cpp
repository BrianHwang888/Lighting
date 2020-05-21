#include "keyboard.h"

keyboard::keyboard() {};

void keyboard::keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	
}