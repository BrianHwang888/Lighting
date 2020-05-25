#ifndef __CUBE_H__
#define __CUBE_H__

#include"render_object.h"

class cube :public render_object
{
public:
	cube();
	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file_path) override;

protected:
	glm::vec4* colors;
	glm::mat4* model_matrix;

private:

};

#endif // !__CUBE_H__
