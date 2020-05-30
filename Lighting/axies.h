#ifndef __AXIES_H__
#define __AXIES_H__

#include"render_object.h"

class Axies : public render_object
{
public:
	Axies();
	Axies(const Axies& other);
	void gen_buffer(GLuint program) override;
	void draw() override;
	void read_file(const char* file) override;

	Axies& operator=(const Axies& rhs);
protected:
	glm::vec4* colors;

private:
};
#endif // !__AXIES_H__
