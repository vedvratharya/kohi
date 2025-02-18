#pragma once

#include "core/application.h"

/*
 * represetns the basic state in a game
 * called for creation by the application 
 */
typedef struct game {
    // app config
    application_config app_config;

    // pointer to game's initialize function
    b8 (*initialize)(struct game* game_inst);

    // pointer to game's update function
    b8 (*update)(struct game* game_inst, f32 delta_time);

    // pointer to game's render function
    b8 (*render)(struct game* game_inst, f32 delta_time);

    // pointer to handle resizes
    void (*on_resize)(struct game* game_inst, u32 width, u32 height);

    // game-specific game state, created and managed by the game
    void* state;
} game;