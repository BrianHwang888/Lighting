#version 330 core

in vec3 vPosition;
in vec3 vColor;
in vec3 vNormal;

out vec3 color;
out vec3 normal;
out vec3 frag_pos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	gl_Position = projection * view * model  * vec4(vPosition, 1.0f);
	frag_pos = vec3(model * vec4(vPosition, 1.0f));
	color = vec3(vColor.rbg);
	normal = vNormal;
}