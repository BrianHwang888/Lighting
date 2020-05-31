#ifndef __CUBE_H__
#define __CUBE_H__

#include"movable_object.h"

class cube :public movable_object
{
public:
	cube();
	cube(const cube& other);

	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file_path) override;
	

	cube& operator=(const cube& rhs);
protected:
	glm::vec4* colors;

private:

};

#endif // !__CUBE_H__
