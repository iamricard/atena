// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include <jansson.h>
#include <cstdio>

#include "Game/Game.h"
#include "Textures/TextureManager.h"

Game *game = NULL;
TextureManager *textures = NULL;

int main(int argc, char const *argv[]) {
    game = new Game("Atena Game Engine v0.0.1",
                    100, 100,
                    640, 480,
                    SDL_WINDOW_RESIZABLE);

    textures = new TextureManager(game->getRenderer());

    textures->loadTexture("test1",
            "assets/test1.json",
            "assets/test1.png");

    textures->getTextureJSON("test1");

    while (game->running()) {
        game->handleEvents();
        // game->update();
        game->render();
    }

    game->clean();

    return 0;
}
