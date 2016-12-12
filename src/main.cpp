/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifdef __GNUC__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <stdio.h>
#ifdef WINDOWS
  #include <direct.h>
  #define GetCurrentDir _getcwd
#else
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

#include <jansson.h>
#include <cstdio>

#include "Textures/TextureManager.h"
#include "Core/Game.h"
#include "Core/InputHandler.h"

const int FPS = 120;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *argv[]) {
  char cCurrentPath[FILENAME_MAX];
  if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
      return 1;
  }

  printf("Current working directory is %s\n", cCurrentPath);

  Uint32 frameStart, frameTime;
  Game *AGEGame = new Game();
  if (AGEGame->init("Atena Game Engine v0.0.1",
                    100, 100, 640, 480, 0)) {
    AGEInput::Instance()->init(AGEGame);
    AGETextures::Instance()->load("Sprites1",
                      std::string(cCurrentPath) + "/test_assets/Sprites1.json",
                      std::string(cCurrentPath) + "/test_assets/Sprites1.png",
                      AGEGame->getRenderer());

    while (AGEGame->running()) {
      frameStart = SDL_GetTicks();

      AGEGame->handleEvents();
      AGEGame->update();
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
