/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Game/Game.h"

Game *game = NULL;

int main(int argc, char const *argv[]) {
    game = new Game("Atena Game Engine v0.0.1",
                    100, 100,
                    640, 480,
                    SDL_WINDOW_RESIZABLE);

    AGETextures::Instance()->load("Sprites1",
                      "/home/stark/Gamedev/Atena/test_assets/Sprites1.json",
                      "/home/stark/Gamedev/Atena/test_assets/Sprites1.png",
                      game->getRenderer());

    while (game->running()) {
        game->handleEvents();
        game->render();
    }

    game->clean();

    return 0;
}
