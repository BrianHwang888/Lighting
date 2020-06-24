#version 330 core

in vec3 vPosition;
in vec4 vColor;
in vec3 vNormal;

out vec3 color;
out vec3 normal;
out vec3 frag_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	frag_pos = vec3(model * vec4(vPosition, 1.0f));
	
	color = vec3(vColor.rgb);
	normal = mat3(transpose(inverse(model))) * vNormal;

	gl_Position = projection * view * vec4(frag_pos, 1.0f);
}