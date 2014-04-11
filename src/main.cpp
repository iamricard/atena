/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Game/Game.h"
#include "Textures/TextureManager.h"
#include "Sprites/SpriteManager.h"

Game *game = NULL;
TextureManager *textures = NULL;
SpriteManager *sprites = NULL;

int main(int argc, char const *argv[]) {
    game = new Game("Atena Game Engine v0.0.1",
                    100, 100,
                    640, 480,
                    SDL_WINDOW_RESIZABLE);

    textures = new TextureManager(game->getRenderer());
    sprites = new SpriteManager();

    textures->loadTexture("test1", "assets/test1.json", "assets/test1.png");
    sprites->addSprite("FRLG_Red_Back", textures->getTexture("test1"), 50, 50);

    // textures->getTextureJSON("test1");

    while (game->running()) {
        game->handleEvents();
        sprites->renderSprites(game->getRenderer());
        // game->update();
        game->render();
    }

    game->clean();

    return 0;
}
