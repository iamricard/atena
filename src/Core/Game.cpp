/**
 * Atena Game Engine
 * Game.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <assert.h>
#include <cstdio>
#include "./Game.h"
#include "../Sprite/Sprite.h"

bool Game::instantiated_ = false;

Game::Game() :
    m_pWindow(0),
    m_pRenderer(0),
    m_Running(false) {
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

    m_pWindow = SDL_CreateWindow(title,
                                 xpos, ypos,
                                 width, height,
                                 flags);

    if (m_pWindow != 0) {
      printf("SDL_CreateWindow success\n");

      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0) {
        printf("SDL_CreateRenderer success\n");
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

        m_objectFactory = new GameObjectFactory();

        if (m_objectFactory != NULL) {
          printf("Object Factory correctly created\n");
        } else {
          printf("GameObjectFactory error\n");
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
  m_Running = true;

  m_objectFactory->registerType("Sprite", new SpriteCreator());
  GameObject *example = m_objectFactory->create("Sprite");
  example->load(new LoaderParams("Sprites1", "bahamut", 100, 100));
  m_gameObjects.push_back(example);

  return true;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);
  drawGameObjects();
  SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
  for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
    m_gameObjects[i]->update();
  }
}

void Game::clean() {
  printf("Cleaning game\n");

  AGEInput::Instance()->clean();

  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::handleEvents() {
  AGEInput::Instance()->update();
}

void Game::drawGameObjects() {
  for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
    m_gameObjects[i]->draw(m_pRenderer);
  }
}
