/**
 * Atena Game Engine
 * base-entity.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef __ATENA_ENTITIES_BASE_ENTITY__
#define __ATENA_ENTITIES_BASE_ENTITY__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "atena/math/vector-2d.h"
#include "atena/textures/texture-manager.h"
#include "./atena/entities/entity-config.h"

class BaseEntity {
public:
  virtual void load(const EntityConfig* pParams) = 0;
  virtual void draw(SDL_Renderer *ren) = 0;
  virtual void update() = 0;
  virtual void clean() = 0;

protected:
  BaseEntity();
  ~BaseEntity() {}

  int m_width;
  int m_height;

  int m_row;
  int m_frame;

  bool m_json;

  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;

  std::string m_textureKey;
  std::string m_frameKey;
};

class EntityBuilder {
public:
  virtual BaseEntity* Build() const = 0;
  virtual ~EntityBuilder() {}
};

#endif
