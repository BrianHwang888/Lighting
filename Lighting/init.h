#ifndef __INIT_H__
#define __INIT_H__

#include"shader.h"
#include"render_object.h"
#include"floor.h"
#include"axies.h"
#include"camera.h"

#define NUM_OBJECTS 2

void init(Shader** shader_array, render_object** rendering_objects_array);
render_object** init_rendering_obj();
Floor* init_floor();
camera* init_main_camera();
Axies* init_grid();
#endif