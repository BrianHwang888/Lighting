#ifndef __MOUSE_H__
#define __MOUSE_H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>

class mouse {

public:
	void mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos);
	mouse(float window_width, float window_height);

private:
	float last_x;
	float last_y;
	float x_offset;
	float y_offset;

};


#endif // !__MOUSE_H__
