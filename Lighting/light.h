#ifndef __LIGHT__H__
#define __LIGHT__H__

#include<glfw/glfw3.h>
#include<glad/glad.h>
#include<glm/common.hpp>

class light {
public:
	light();
	light(glm::vec3 light_pos, glm::vec4 light_color);
	~light();

protected:
	glm::vec4 color;
	glm::vec3 position;
};

#endif // !__LIGHT__H__
