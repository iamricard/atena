/**
 * Atena Game Engine
 * Bahamut.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Bahamut.h"

void Bahamut::draw(SDL_Renderer *ren) {
    GameObject::draw(ren);
}

void Bahamut::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);
    handleInput();
    GameObject::update();
}

void Bahamut::clean() {
    GameObject::clean();
    printf("Cleaning Bahamut\n");
}

void Bahamut::handleInput() {
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
