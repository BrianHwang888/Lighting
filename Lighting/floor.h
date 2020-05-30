#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "render_object.h"

class Floor: public render_object {
public:
	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file) override;
	Floor();
	Floor(const char* file);
	Floor(const Floor& other);

	Floor& operator=(const Floor& rhs);
protected:
	glm::vec4* colors;

private:
};

#endif // !__FLOOR_H__
