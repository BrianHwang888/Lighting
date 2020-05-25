/*----- Basic Vertex Shader -----*/
#version 330 core

in vec3 vPosition;
in vec4 vColor;

out vec4 color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main(){

	gl_Position = projection * view * model * vec4(vPosition, 1.0f);
	color = vColor;

}