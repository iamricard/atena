/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Game/Game.h"

Game *game = NULL;
TextureManager *textures = NULL;
SpriteManager *sprites = NULL;

int main(int argc, char const *argv[]) {
    game = new Game("Atena Game Engine v0.0.1",
                    100, 100,
                    640, 480,
                    SDL_WINDOW_RESIZABLE);
    game->enableSprites();
    game->enableTextures();

    game->loadTexture("Sprites1",
                      "/home/stark/Gamedev/Atena/test_assets/Sprites1.json",
                      "/home/stark/Gamedev/Atena/test_assets/Sprites1.png",
                      game->getRenderer());

    game->addSprite("bahamut.png",
                    game->getTexture("Sprites1"),
                    100, 100);

    while (game->running()) {
        game->handleEvents();
        game->render();
    }

    game->clean();

    return 0;
}
