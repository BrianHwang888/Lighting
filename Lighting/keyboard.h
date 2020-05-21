#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class keyboard {
public:
	void keyboard_input_callback(GLFWwindow* window, int key, int scancode, int action, int mod);
	keyboard();
};

#endif // !__KEYBOARD_H__
