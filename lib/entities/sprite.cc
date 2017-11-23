/**
 * Atena Game Engine
 * sprite.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/entities/sprite.h"

void Sprite::load(const EntityConfig* config) { BaseEntity::load(config); }

void Sprite::draw(SDL_Renderer* renderer) { BaseEntity::draw(renderer); }

void Sprite::update() {
  velocity.set_x_position(0);
  velocity.set_y_position(0);
  handleInput();
  BaseEntity::update();
}

void Sprite::clean() {
  BaseEntity::clean();
  printf("Cleaning Sprite\n");
}

void Sprite::handleInput() {
  if (AGEInput::Instance()->joysticksInitialised()) {
    if (AGEInput::Instance()->get_x_positionAxis(0, 1) > 0 ||
        AGEInput::Instance()->get_x_positionAxis(0, 1) < 1) {
      velocity.set_x_position(1 *
                              AGEInput::Instance()->get_x_positionAxis(0, 1));
    }

    if (AGEInput::Instance()->get_y_positionAxis(0, 1) > 0 ||
        AGEInput::Instance()->get_y_positionAxis(0, 1) < 1) {
      velocity.set_y_position(1 *
                              AGEInput::Instance()->get_y_positionAxis(0, 1));
    }
  }
}
