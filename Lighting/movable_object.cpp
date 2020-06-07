#include "movable_object.h"

void movable_object::translate(glm::vec3 disposition) {	model_matrix = glm::translate(model_matrix, disposition); }
void movable_object::rotate(GLfloat angle, glm::vec3 axies) { model_matrix = glm::rotate(model_matrix, angle, axies); }
void movable_object::scale(glm::vec3 scale_factor) { model_matrix = glm::scale(model_matrix, scale_factor); }
void movable_object::set_velocity(glm::vec3 velo) { velocity = velo; }
void movable_object::set_model_matrix(glm::mat4 model) { model_matrix = model; }
glm::vec3 movable_object::get_position() { return position; }
glm::vec3 movable_object::get_velocity() { return velocity; }
glm::mat4 movable_object::get_model_matrix() { return model_matrix; }