#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "render_object.h"

class floor: public render_object {
public:
	void gen_buffer(GLuint program) override;
	void draw() override;
	floor();

protected:
	glm::vec4* colors;

private:
};

#endif // !__FLOOR_H__
