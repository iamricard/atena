/**
 * Atena Game Engine
 * sprite.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_ENTITIES_SPRITE_H_
#define LIB_ENTITIES_SPRITE_H_

#include "./atena/entities/base-entity.h"
#include "./atena/entities/entity-config.h"
#include "atena/input/input-handler.h"

class Sprite : public BaseEntity {
 public:
  Sprite() : BaseEntity() {}
  ~Sprite();

  void Load(const EntityConfig* config);
  void Draw(SDL_Renderer* renderer);
  void Update();
  void Clean();

 private:
  void HandleInput();
};

class SpriteBuilder : public EntityBuilder {
  BaseEntity* Build() const { return new Sprite(); }
};

#endif  // LIB_ENTITIES_SPRITE_H_
