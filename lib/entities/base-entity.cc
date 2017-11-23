/**
 * Atena Game Engine
 * entity.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/entities/base-entity.h"

BaseEntity::BaseEntity() :
  m_width(0),
  m_height(0),
  m_row(0),
  m_frame(0),
  m_json(false) {}

void BaseEntity::load(const EntityConfig *pParams) {
  m_position.setX(pParams->getX());
  m_position.setY(pParams->getY());

  m_width = pParams->getWidth();
  m_height = pParams->getHeight();

  m_textureKey = pParams->getTextureKey();
  m_frameKey = pParams->getFrameKey();

  m_row = 1;
  m_frame = 1;

  m_json = pParams->isJSON();
}

void BaseEntity::draw(SDL_Renderer *ren) {
  if (!m_json) {
    AGETextures::Instance()->drawFrame(m_textureKey,
        m_position.getX(), m_position.getY(),
        m_width, m_height,
        m_row, m_frame,
        ren);
  } else {
    AGETextures::Instance()->drawFrame(m_textureKey, m_frameKey,
        m_position.getX(), m_position.getY(),
        ren);
  }
}

void BaseEntity::update() {
  m_velocity += m_acceleration;
  m_position += m_velocity;
}

void BaseEntity::clean() {}
