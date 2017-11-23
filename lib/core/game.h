/**
 * Atena Game Engine
 * game.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <vector>

#include "atena/input/input-handler.h"
#include "atena/entities/base-entity.h"
#include "atena/entities/entity-factory.h"

class Game {
public:
  Game();
  ~Game() {}

  bool init(const char *title,
          int xpos, int ypos,
          int width, int height,
          int flags);
  void render();
  void update();
  void handleEvents();
  void clean();
  void quit() { is_running = false; }

  void drawEntities();

  SDL_Renderer* getRenderer() const { return renderer; }
  bool running() { return is_running; }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;

  bool is_running;
  static bool instantiated_;

  EntityFactory *entity_factory;

  std::vector<BaseEntity*> entities;
};

#endif
