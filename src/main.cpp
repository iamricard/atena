/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Core/InputHandler.h"
#include "Core/Game.h"
#include "Textures/TextureManager.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char const *argv[]) {
    Uint32 frameStart, frameTime;
    Game *AGEGame = new Game();
    if (AGEGame->init("Atena Game Engine v0.0.1",
                      100, 100, 640, 480, 0)) {
        AGEInput::Instance()->init(AGEGame);
        AGETextures::Instance()->load("Sprites1",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.json",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.png",
                          AGEGame->getRenderer());

        while (AGEGame->running()) {
            frameStart = SDL_GetTicks();

            AGEGame->handleEvents();
            AGEGame->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME) {
                SDL_Delay(static_cast<int>((DELAY_TIME - frameTime)));
            }
        }
    }



    AGEGame->clean();

    return 0;
}
