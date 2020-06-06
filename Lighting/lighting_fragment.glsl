#version 330 core

in vec3 color;
in vec3 normal;
in vec3 frag_pos;

uniform vec3 light_color;
uniform vec3 light_pos;
uniform vec3 viewer_pos;

uniform int shininess;
uniform float ambient_strength;
uniform float specular_strength;
uniform bool is_ambient_lighting;
uniform bool is_diffuse_lighting;
uniform bool is_specular_lighting;

out vec4 frag_color;

void main(){
	vec3 result;
	
	if(is_ambient_lighting){
		vec3 ambient = ambient_strength * light_color;
		result = ambient * color;
	}

	else if(is_diffuse_lighting){
		vec3 norm = normalize(normal);
		vec3 light_dir = normalize(light_pos - frag_pos);
		float diff = max(dot(norm, light_dir), 0.0f);
		vec3 ambient = ambient_strength * light_color;
		vec3 diffuse = diff * light_color;
		result = (ambient + diffuse) * color;
	}

	else if(is_specular_lighting){
		vec3 norm = normalize(normal);
		vec3 viewer_dir = normalize(viewer_pos - frag_pos);
		vec3 light_dir = normalize(light_pos - light_pos);
		vec3 reflect_dir = reflect(-light_dir, norm);
		float spec = pow(max(dot(viewer_dir, reflect_dir), 0.0f), shininess);

		vec3 ambient = ambient_strength * light_color;
		float diff = max(dot(norm, light_dir), 0.0f);
		vec3 diffuse = diff * light_color;
		vec3 specular = specular_strength * spec * light_color;
		result = (ambient + diffuse + specular) * color;
	}
	frag_color = vec4(result, 1.0f);
}