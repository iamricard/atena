/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Game/Game.h"
#include "Textures/TextureManager.h"
#include "Sprites/Sprite.h"

Game *game = NULL;
TextureManager *textures = NULL;
// SpriteManager *sprites = NULL;

int main(int argc, char const *argv[]) {
    game = new Game("Atena Game Engine v0.0.1",
                    100, 100,
                    640, 480,
                    SDL_WINDOW_RESIZABLE);

    textures = new TextureManager();

    textures->loadTexture("Sprites1",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.json",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.png",
                          game->getRenderer());

    Sprite* sprite = new Sprite("bahamut.png",
                                textures->getTexture("Sprites1"),
                                100, 100);

    while (game->running()) {
        game->handleEvents();

        // this needs to be different eventually it is this way
        // for testing purposes
        game->render();
        sprite->render(game->getRenderer());
        SDL_RenderPresent(game->getRenderer());
    }

    game->clean();

    return 0;
}
