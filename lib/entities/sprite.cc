/**
 * Atena Game Engine
 * sprite.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/entities/sprite.h"

void Sprite::Load(const EntityConfig* config) { BaseEntity::Load(config); }

void Sprite::Draw(SDL_Renderer* renderer) { BaseEntity::Draw(renderer); }

void Sprite::Update() {
  BaseEntity::Update();
  velocity.set_x_position(0);
  velocity.set_y_position(0);
  HandleInput();
}

void Sprite::Clean() {
  BaseEntity::Clean();
  printf("Cleaning Sprite\n");
}

void Sprite::HandleInput() {
  if (AGEInput::Instance()->is_initialized()) {
    if (AGEInput::Instance()->get_joystick_pos_x(0, 1) > 0 ||
        AGEInput::Instance()->get_joystick_pos_x(0, 1) < 1) {
      velocity.set_x_position(1 *
                              AGEInput::Instance()->get_joystick_pos_x(0, 1));
    }

    if (AGEInput::Instance()->get_joystick_pos_y(0, 1) > 0 ||
        AGEInput::Instance()->get_joystick_pos_y(0, 1) < 1) {
      velocity.set_y_position(1 *
                              AGEInput::Instance()->get_joystick_pos_y(0, 1));
    }
  }
}
