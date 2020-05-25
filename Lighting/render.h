#ifndef __RENDER_H__
#define __RENDER_H__

#include"shader.h"
#include"render_object.h"
#include"floor.h"
#include"camera.h"

#define NUM_OBJECTS 2

extern camera* main_camera;

void render(Shader** shader_array, render_object** render_object_array);
void display(Shader** shader_array);

#endif // !__RENDER_H__
