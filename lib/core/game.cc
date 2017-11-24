/**
 * Atena Game Engine
 * Game.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "atena/core/game.h"
#include <assert.h>
#include <cstdio>
#include "atena/entities/sprite.h"

bool Game::instantiated_ = false;

Game::Game() : window(0), renderer(0) {
  assert(!instantiated_);
  instantiated_ = true;
  has_quit = false;
}

bool Game::Init(const char* title, int xpos, int ypos, int width, int height,
                int flags) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) == 0) {
    // TODO(rcsole): Maybe add a SDL_WasInit for each and check?
    printf("\nSYSTEMS INITIALISED:\n");
    printf("  * VIDEO INITIALISED\n");
    printf("  * EVENTS INITIALISED\n");
    printf("  * AUDIO INITIALISED\n\n");

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

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

  printf("Init success\n");

  entity_factory->RegisterEntityBuilder("Sprite", new SpriteBuilder());
  BaseEntity* example = entity_factory->Build("Sprite");
  example->Load(new EntityConfig("Sprites1", "bahamut", 100, 100));
  entities.push_back(example);

  return true;
}

void Game::Render() {
  SDL_RenderClear(renderer);
  DrawEntities();
  SDL_RenderPresent(renderer);
}

void Game::Update() {
  for (std::vector<BaseEntity*>::size_type i = 0; i != entities.size(); i++) {
    entities[i]->Update();
  }
}

void Game::Quit() { has_quit = true; }

void Game::Clean() {
  printf("Cleaning game\n");

  AGEInput::Instance()->Clean();

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::HandleEvents() { AGEInput::Instance()->Update(); }

void Game::DrawEntities() {
  for (std::vector<BaseEntity*>::size_type i = 0; i != entities.size(); i++) {
    entities[i]->Draw(renderer);
  }
}

bool Game::KeepRunning() { return !has_quit; }
