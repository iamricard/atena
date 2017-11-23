/**
 * Atena Game Engine
 * sprite.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/entities/sprite.h"

void Sprite::load(const EntityConfig* pParams) {
  BaseEntity::load(pParams);
}

void Sprite::draw(SDL_Renderer *ren) {
  BaseEntity::draw(ren);
}

void Sprite::update() {
  m_velocity.setX(0);
  m_velocity.setY(0);
  handleInput();
  BaseEntity::update();
}

void Sprite::clean() {
  BaseEntity::clean();
  printf("Cleaning Sprite\n");
}

void Sprite::handleInput() {
  if (AGEInput::Instance()->joysticksInitialised()) {
    if (AGEInput::Instance()->getXAxis(0, 1) > 0
      || AGEInput::Instance()->getXAxis(0, 1) < 1) {
      m_velocity.setX(1 * AGEInput::Instance()->getXAxis(0, 1));
    }

    if (AGEInput::Instance()->getYAxis(0, 1) > 0
      || AGEInput::Instance()->getYAxis(0, 1) < 1) {
      m_velocity.setY(1 * AGEInput::Instance()->getYAxis(0, 1));
    }
  }
}
