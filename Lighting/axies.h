#ifndef __AXIES_H__
#define __AXIES_H__

#include"render_object.h"

class axies: public render_object
{
public:
	axies();
	void gen_buffer(GLuint program) override;
	void draw() override;

protected:
	glm::vec4* colors;

private:

#endif // !__AXIES_H__
