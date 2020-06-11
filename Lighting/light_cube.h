#ifndef __LIGHT_CUBE_H__
#define __LIGHT_CUBE_H__

#include"cube.h"
#include"light.h"

class light_cube : public cube {
public:
	light_cube();
	light_cube(const light_cube& other);
	~light_cube();

	int get_light_type();
	float get_ambient_strength();
	float get_specular_strength();
	void gen_buffer(GLuint program);
	void set_light_color(glm::vec4 light_color);
	glm::vec4 get_light_color();

	light_cube& operator=(const light_cube& rhs) ;

protected:
	light* cube_light;

};

#endif // !__LIGHT_CUBE_H__
