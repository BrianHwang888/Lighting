#ifndef __LIGHT__H__
#define __LIGHT__H__

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/common.hpp>

/*----- light_types: 0:ambient light; 1:diffuse light; 2:sepcular light -----*/
typedef struct light_type{ int light_type; }light_type;

class light {
public:
	light();
	light(light& other);
	light(glm::vec3 light_pos, glm::vec4 light_color);

	int get_type();
	float ambient_strength;
	float diffuse_strength;
	float specular_strength;

	void set_color(glm::vec4 light_color);
	void set_as_ambient(float strength);
	void set_as_diffuse(float amb_strength, float diff_strength);
	void set_as_specular(float amb_strength, float diff_strength, float spec_strength);
	
	glm::vec3 get_light_position();
	glm::vec4 get_light_color();
	
	light& operator=(light& rhs);

	~light();

protected:
	light_type type;
	glm::vec4 color;
	glm::vec3 position;

};

#endif // !__LIGHT__H__
