/**
 * Atena Game Engine
 * game.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_CORE_GAME_H_
#define LIB_CORE_GAME_H_

#include <SDL2/SDL.h>
#include <vector>

#include "atena/entities/base-entity.h"
#include "atena/entities/entity-factory.h"
#include "atena/input/input-handler.h"

class Game {
 public:
  Game();
  ~Game() {}

  bool init(const char *title, int xpos, int ypos, int width, int height,
            int flags);
  void render();
  void update();
  void handleEvents();
  void clean();
  void quit() { is_running = false; }

  void drawEntities();

  SDL_Renderer *getRenderer() const { return renderer; }
  bool running() { return is_running; }

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  bool is_running;
  static bool instantiated_;

  EntityFactory *entity_factory;

  std::vector<BaseEntity *> entities;
};

#endif  // LIB_CORE_GAME_H_
