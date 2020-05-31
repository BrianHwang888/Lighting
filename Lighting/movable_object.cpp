#include "movable_object.h"

void movable_object::translate(glm::vec3 disposition) {
	model_matrix = glm::translate(model_matrix, disposition);
}
void movable_object::rotate(GLfloat angle, glm::vec3 axies) {
	model_matrix = glm::rotate(model_matrix, angle, axies);
}
void movable_object::scale(glm::vec3 scale_factor) {
	model_matrix = glm::scale(model_matrix, scale_factor);
}