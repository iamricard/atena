/**
 * Atena Game Engine
 * Sprite.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Sprite.h"

void Sprite::load(const LoaderParams* pParams) {
    GameObject::load(pParams);
}

void Sprite::draw(SDL_Renderer *ren) {
    GameObject::draw(ren);
}

void Sprite::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    GameObject::update();
}

void Sprite::clean() {
    GameObject::clean();
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
