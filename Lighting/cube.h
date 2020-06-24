#ifndef __CUBE_H__
#define __CUBE_H__

#include"color_object.h"
#include"movable_object.h"

class cube :public color_obj
{
public:
	movable_object* model;

	cube();
	cube(const cube& other);

	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file_path) override;
	

	cube& operator=(const cube& rhs);

};

#endif // !__CUBE_H__
