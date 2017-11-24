/**
 * Atena Game Engine
 * base-entity.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_ENTITIES_BASE_ENTITY_H_
#define LIB_ENTITIES_BASE_ENTITY_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "./atena/entities/entity-config.h"
#include "atena/math/vector-2d.h"
#include "atena/textures/texture-manager.h"

class BaseEntity {
 public:
  virtual void Load(const EntityConfig* config) = 0;
  virtual void Draw(SDL_Renderer* renderer) = 0;
  virtual void Update() = 0;
  virtual void Clean() = 0;

 protected:
  BaseEntity();
  ~BaseEntity() {}

  int width;
  int height;

  int row;
  int frame;

  bool json;

  Vector2D position;
  Vector2D velocity;
  Vector2D acceleration;

  std::string textureKey;
  std::string frameKey;
};

class EntityBuilder {
 public:
  virtual BaseEntity* Build() const = 0;
  virtual ~EntityBuilder() {}
};

#endif  // LIB_ENTITIES_BASE_ENTITY_H_
