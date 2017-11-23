/**
 * Atena Game Engine
 * sprite.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "./atena/entities/base-entity.h"
#include "./atena/entities/entity-config.h"
#include "atena/input/input-handler.h"

class Sprite : public BaseEntity {
 public:
  Sprite() : BaseEntity() {}
  ~Sprite();

  void load(const EntityConfig* config);
  void draw(SDL_Renderer* renderer);
  void update();
  void clean();

 private:
  void handleInput();
};

class SpriteBuilder : public EntityBuilder {
  BaseEntity* Build() const { return new Sprite(); }
};
