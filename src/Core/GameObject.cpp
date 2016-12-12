/**
 * Atena Game Engine
 * GameObject.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./GameObject.h"

GameObject::GameObject() :
  m_width(0),
  m_height(0),
  m_row(0),
  m_frame(0),
  m_json(false) {}

void GameObject::load(const LoaderParams *pParams) {
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

void GameObject::draw(SDL_Renderer *ren) {
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

void GameObject::update() {
  m_velocity += m_acceleration;
  m_position += m_velocity;
}

void GameObject::clean() {}
