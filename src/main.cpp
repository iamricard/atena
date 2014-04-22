/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <jansson.h>
#include <cstdio>

#include "Core/Game.h"
#include "Textures/TextureManager.h"
#include "Core/InputHandler.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char const *argv[]) {
    Uint32 frameStart, frameTime;
    if (AGEGame::Instance()->init("Atena Game Engine v0.0.1",
                                100, 100, 640, 480, 0)) {

        AGETextures::Instance()->load("Sprites1",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.json",
                          "/home/stark/Gamedev/Atena/test_assets/Sprites1.png",
                          AGEGame::Instance()->getRenderer());

        while (AGEGame::Instance()->running()) {
            frameStart = SDL_GetTicks();

            AGEGame::Instance()->handleEvents();
            AGEGame::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME) {
                SDL_Delay(static_cast<int>((DELAY_TIME - frameTime)));
            }
        }
    }



    AGEGame::Instance()->clean();

    return 0;
}
