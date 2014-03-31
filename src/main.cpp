// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include <cstdio>
#include "Game/Game.h"

Game* game = 0;

int main(int argc, char const *argv[]) {
    game = new Game();

    game->init("Game Engine v0.0.1",
            100, 100,
            640, 480,
            SDL_WINDOW_RESIZABLE);

    while (game->running()) {
        game->handleEvents();
        // game->update();
        game->render();
    }

    // printf("OK Bye");

    game->clean();

    return 0;
}
