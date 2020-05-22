#ifndef __INIT_H__
#define __INIT_H__

#include"shader.h"
#include"render_object.h"
#include"floor.h"

#define NUM_OBJECTS 1

void init(Shader** shader_array, render_object** rendering_objects_array);
render_object** init_rendering_obj();
Floor* init_floor();

#endif