/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include <SDL2/SDL.h>
#include <jansson.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdio>

#include "atena/core/game.h"
#include "atena/input/input-handler.h"
#include "atena/textures/texture-manager.h"

const int FPS = 120;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char *argv[]) {
  char working_path[FILENAME_MAX];
  if (!getcwd(working_path, sizeof(working_path))) {
    return 1;
  }

  printf("Current working directory is %s\n", working_path);

  Uint32 frameStart, frameTime;
  Game *game = new Game();
  if (game->Init("Atena Game Engine v0.0.1", 100, 100, 640, 480, 0)) {
    AGEInput::Instance()->Init();
    AGEInput::Instance()->On(Event::Quit, [game]() { game->Quit(); });
    AGETextures::Instance()->Load(
        "Sprites1", std::string(working_path) + "/test_assets/Sprites1.json",
        std::string(working_path) + "/test_assets/Sprites1.png",
        game->get_renderer());

    while (game->KeepRunning()) {
      frameStart = SDL_GetTicks();

      game->HandleEvents();
      game->Update();
      game->Render();

      frameTime = SDL_GetTicks() - frameStart;

      if (frameTime < DELAY_TIME) {
        SDL_Delay(static_cast<int>((DELAY_TIME - frameTime)));
      }
    }
  }

  game->Clean();

  return 0;
}
