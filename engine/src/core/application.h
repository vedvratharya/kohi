#pragma once

#include "defines.h"

struct game;

typedef struct application_config {
    // window starting position x-axis
    i16 start_pos_x;
    
    // window starting position y-axis
    i16 start_pos_y;
    
    // window starting width
    i16 start_width;
    
    // window starting height
    i16 start_height;
    
    // application name used in windowing
    char* name;
    
} application_config;

KAPI b8 application_create(struct game* game_inst);

KAPI b8 application_run();