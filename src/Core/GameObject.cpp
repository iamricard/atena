/**
 * Atena Game Engine
 * GameObject.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./GameObject.h"

// @fixme(rcsole): STACK OVERFLOW
GameObject::GameObject(const LoaderParams *pParams) : GameObject(pParams) {
    m_x = pParams->getX();
    m_x = pParams->getY();

    m_width = pParams->getWidth();
    m_height = pParams->getHeight();

    m_textureKey = pParams->getTextureKey();
    m_frameKey = pParams->getFrameKey();

    m_row = 1;
    m_frame = 1;
}

void GameObject::draw(SDL_Renderer *ren) {
    if (m_frameKey.empty()) {
        AGETextures::Instance()->drawFrame(m_textureKey,
            m_x, m_y, m_width, m_height, m_row, m_frame,
            ren);
    } else {
        AGETextures::Instance()->drawFrame(m_textureKey, m_frameKey, m_x, m_y,
            ren);
    }
}

void GameObject::update() {}
void GameObject::clean() {}
