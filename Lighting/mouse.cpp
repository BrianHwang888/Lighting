#include "mouse.h"

mouse::mouse(float window_width, float window_height) {
	last_x = window_width / 2;
	last_y = window_height / 2;
}

void mouse::mouse_input_callback(GLFWwindow* window, double x_pos, double y_pos) {
	x_offset = x_pos - last_x;
	y_offset = last_y - y_pos;

	last_x = x_pos;
	last_y = y_pos;

}