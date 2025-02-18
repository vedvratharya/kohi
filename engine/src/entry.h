#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// externally defined function to create a game
extern b8 create_game(game* out_game);

// main entry point of the application
int main(void) {

    // request the game instance from the application
    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1;
    }

    // ensure function pointers exist
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        KFATAL("The game's function pointers must be assigned!");
        return -2;
    }
    
    // initialization
    if (!application_create(&game_inst)) {
        KINFO("Application failed to create game instance!");
        return 1;
    }

    // begin the game loop
    if(!application_run()) {
        KINFO("Application did not shutdown gracefully");
        return 2;
    }
    
    return 0;
}