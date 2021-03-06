#ifndef __FLOOR_H__
#define __FLOOR_H__

#include"shading_object.h"

class Floor: public shading_obj {
public:
	void gen_buffer(GLuint program);
	void draw();
	void read_file(const char* file);
	Floor();
	Floor(const char* file);
	Floor(const Floor& other);

	Floor& operator=(const Floor& rhs);
};

#endif // !__FLOOR_H__
