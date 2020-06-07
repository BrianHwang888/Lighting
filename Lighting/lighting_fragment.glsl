#version 330 core
/*----- light_type value: 0:ambient light; 1:diffuse light; 2: specular light -----*/
in vec3 color;
in vec3 normal;
in vec3 frag_pos;

uniform vec3 light_color;
uniform vec3 light_pos;
uniform vec3 viewer_pos;

uniform int shininess;
uniform float ambient_strength;
uniform float specular_strength;
uniform int light_type;

out vec4 frag_color;

void main(){
	vec3 result;
	
	if(light_type == 0){
		vec3 ambient = ambient_strength * light_color;
		result = ambient * color;
	}

	else if(light_type == 1){
		vec3 norm = normalize(normal);
		vec3 light_dir = normalize(light_pos - frag_pos);
		float diff = max(dot(norm, light_dir), 0.0f);
		vec3 ambient = ambient_strength * light_color;
		vec3 diffuse = diff * light_color;
		result = (ambient + diffuse) * color;
	}

	else if(light_type == 2){
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