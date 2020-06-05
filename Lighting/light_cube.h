#ifndef __LIGHT_CUBE_H__
#define __LIGHT_CUBE_H__

#include"cube.h"
#include"light.h"

class light_cube : public cube {
public:
	light_cube();
	light_cube(const light_cube& other);
	~light_cube();
	void gen_buffer(GLuint program);
	
	light_cube& operator=(const light_cube& rhs) ;

private:
	light* cube_light;

};

#endif // !__LIGHT_CUBE_H__