#ifndef __LIGHT_CUBE_H__
#define __LIGHT_CUBE_H__

#include"cube.h"
#include"light.h"

class light_cube : public cube {
public:
	light* cube_light;

	light_cube();
	light_cube(const light_cube& other);
	~light_cube();
	light_cube& operator=(const light_cube& rhs);

	void gen_buffer(GLuint program);


};

#endif // !__LIGHT_CUBE_H__
