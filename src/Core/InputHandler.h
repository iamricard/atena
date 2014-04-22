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

#include "../Utils/Vector2D.h"

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

    int getXAxis(int pad, int stick) const;
    int getYAxis(int pad, int stick) const;

    void initialiseJoysticks();
    bool joysticksInitialised() { return m_bJoysticksInitialised; }

 private:
    InputHandler():
        m_joystickDeadZone(10000) {}
    ~InputHandler() {}

    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;

    bool m_bJoysticksInitialised;

    int m_joystickDeadZone;

    static InputHandler* s_pInstance;
};
typedef InputHandler AGEInput;

#endif
