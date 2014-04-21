/**
 * Atena Game Engine
 * InputHandler.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __InputHandler__
#define __InputHandler__

#include <SDL2/SDL.h>
#include <vector>

#include "./Game.h"

class InputHandler {
 public:
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
        }

        return s_pInstance;
    }

    void update();
    void clean();

    void initialiseJoysticks();
    bool joysticksInitialised() { return m_bJoysticksInitialised; }

 private:
    InputHandler() {}
    ~InputHandler() {}

    std::vector<SDL_Joystick*> m_joysticks;
    bool m_bJoysticksInitialised;

    static InputHandler* s_pInstance;
};
typedef InputHandler AGEInput;

#endif
