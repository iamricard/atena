/**
 * Atena Game Engine
 * Game.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <assert.h>
#include <cstdio>
#include "atena/core/game.h"
#include "atena/entities/sprite.h"

bool Game::instantiated_ = false;

Game::Game() :
    window(0),
    renderer(0),
    is_running(false) {
        assert(!instantiated_);
        instantiated_= true;
}

bool Game::init(const char* title, int xpos, int ypos, int width,
                                    int height, int flags) {
  if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_EVENTS || SDL_INIT_AUDIO) == 0) {
    // TODO(rcsole): Maybe add a SDL_WasInit for each and check?
    printf("\nSYSTEMS INITIALISED:\n");
    printf("  * VIDEO INITIALISED\n");
    printf("  * EVENTS INITIALISED\n");
    printf("  * AUDIO INITIALISED\n\n");

    window = SDL_CreateWindow(title,
                                 xpos, ypos,
                                 width, height,
                                 flags);

    if (window != 0) {
      printf("SDL_CreateWindow success\n");

      renderer = SDL_CreateRenderer(window, -1, 0);

      if (renderer != 0) {
        printf("SDL_CreateRenderer success\n");
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        entity_factory = new EntityFactory();

        if (entity_factory != NULL) {
          printf("Object Factory correctly created\n");
        } else {
          printf("EntityFactory error\n");
          return false;
        }
      } else {
        printf("SDL_CreateRenderer error\n");
        return false;
      }
    } else {
      printf("SDL_CreateWindow error\n");
      return false;
    }
  } else {
    printf("SDL_Init error\n");
    return false;
  }

  printf("Init succes\n");
  is_running = true;

  entity_factory->RegisterEntityBuilder("Sprite", new SpriteBuilder());
  BaseEntity *example = entity_factory->create("Sprite");
  example->load(new EntityConfig("Sprites1", "bahamut", 100, 100));
  entities.push_back(example);

  return true;
}

void Game::render() {
  SDL_RenderClear(renderer);
  drawEntities();
  SDL_RenderPresent(renderer);
}

void Game::update() {
  for (std::vector<BaseEntity*>::size_type i = 0; i != entities.size(); i++) {
    entities[i]->update();
  }
}

void Game::clean() {
  printf("Cleaning game\n");

  AGEInput::Instance()->clean();

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::handleEvents() {
  AGEInput::Instance()->update();
}

void Game::drawEntities() {
  for (std::vector<BaseEntity*>::size_type i = 0; i != entities.size(); i++) {
    entities[i]->draw(renderer);
  }
}
