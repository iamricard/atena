/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include <SDL2/SDL.h>
#include <jansson.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>

#define GetCurrentDir getcwd

#include "atena/core/game.h"
#include "atena/input/input-handler.h"
#include "atena/textures/texture-manager.h"

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
  if (AGEGame->Init("Atena Game Engine v0.0.1", 100, 100, 640, 480, 0)) {
    AGEInput::Instance()->Init();
    AGEInput::Instance()->On(Event::Quit, [AGEGame]() { AGEGame->Quit(); });
    AGETextures::Instance()->Load(
        "Sprites1", std::string(cCurrentPath) + "/test_assets/Sprites1.json",
        std::string(cCurrentPath) + "/test_assets/Sprites1.png",
        AGEGame->get_renderer());

    while (AGEGame->KeepRunning()) {
      frameStart = SDL_GetTicks();

      AGEGame->HandleEvents();
      AGEGame->Update();
      AGEGame->Render();

      frameTime = SDL_GetTicks() - frameStart;

      if (frameTime < DELAY_TIME) {
        SDL_Delay(static_cast<int>((DELAY_TIME - frameTime)));
      }
    }
  }

  AGEGame->Clean();

  return 0;
}
