/**
 * Atena Game Engine
 * entity.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/entities/base-entity.h"

BaseEntity::BaseEntity() : width(0), height(0), row(0), frame(0), json(false) {}

void BaseEntity::load(const EntityConfig *config) {
  position.set_x_position(config->get_x_position());
  position.set_y_position(config->get_y_position());

  width = config->get_width();
  height = config->get_height();

  textureKey = config->get_texture_key();
  frameKey = config->get_frame_key();

  row = 1;
  frame = 1;

  json = config->IsJson();
}

void BaseEntity::draw(SDL_Renderer *renderer) {
  if (!json) {
    AGETextures::Instance()->drawFrame(textureKey, position.get_x_position(),
                                       position.get_y_position(), width, height,
                                       row, frame, renderer);
  } else {
    AGETextures::Instance()->drawFrame(textureKey, frameKey,
                                       position.get_x_position(),
                                       position.get_y_position(), renderer);
  }
}

void BaseEntity::update() {
  velocity += acceleration;
  position += velocity;
}

void BaseEntity::clean() {}
