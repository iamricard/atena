// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include <cstdio>
#include "Game/Game.h"

Game *game = NULL;

int main(int argc, char const *argv[]) {
    game = new Game();

    game->init("Atena Game Engine v0.0.1",
            100, 100,
            640, 480,
            SDL_WINDOW_RESIZABLE);

    game->textures->loadTexture("test1", "test1.json", "test1.png");

    while (game->running()) {
        game->handleEvents();
        // game->update();
        game->textures->render();
        game->render();
    }

    game->clean();

    return 0;
}
