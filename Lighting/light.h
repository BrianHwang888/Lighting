#ifndef __LIGHT__H__
#define __LIGHT__H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>

/*----- light_types: 0:ambient light; 1:diffuse light; 2:sepcular light -----*/
typedef struct light_type{ int light_type; }light_type;

class light {
public:

	light_type type;
	glm::vec4 color;
	glm::vec3 position;
	float ambient_strength;
	float specular_strength;

	light();
	light(const light& other);
	light(glm::vec3 light_pos, glm::vec4 light_color);
	~light();

	light& operator=(const light& rhs);

};

#endif // !__LIGHT__H__
