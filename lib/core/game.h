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

  bool Init(const char *title, int xpos, int ypos, int width, int height,
            int flags);
  void Render();
  void Update();
  void HandleEvents();
  void Clean();

  void DrawEntities();

  SDL_Renderer *get_renderer() const { return renderer; }

 private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  EntityFactory *entity_factory;
  std::vector<BaseEntity *> entities;

  static bool instantiated_;
};

#endif  // LIB_CORE_GAME_H_
