/**
 * Atena Game Engine
 * InputHandler.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::initialiseJoysticks() {
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }

    if (SDL_NumJoysticks() > 0) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_Joystick* joy = SDL_JoystickOpen(i);

            if (joy != NULL) {
                printf("Initialised one gamepad\n");
                m_joysticks.push_back(joy);
            } else {
                printf("%s", SDL_GetError());
            }
        }

        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;

        printf("Initialised %zu joystick(s)\n", m_joysticks.size());
    } else {
        m_bJoysticksInitialised = false;
    }
}

void InputHandler::clean() {
    if (m_bJoysticksInitialised) {
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            AGEGame::Instance()->quit();
        }
    }
}
