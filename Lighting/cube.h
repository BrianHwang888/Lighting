#ifndef __CUBE_H__
#define __CUBE_H__

#include<glm/gtc/matrix_transform.hpp>
#include"render_object.h"

class cube :public render_object
{
public:
	cube();
	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file_path) override;
	void set_model_matrix(glm::mat4 model);
	glm::mat4 get_model_matrix();
	
protected:
	glm::vec4* colors;
	glm::mat4 model_matrix;

private:

};

#endif // !__CUBE_H__
