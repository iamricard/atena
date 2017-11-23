/**
 * Atena Game Engine
 * input-handler.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/input/input-handler.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::init() {
  if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0) {
    SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
    printf("\nNEW SYSTEM INITIALISED\n");
    printf("  * GAMECONTROLLER INITIALISED\n\n");
  }

  if (SDL_NumJoysticks() > 0) {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
      SDL_GameController* joy = SDL_GameControllerOpen(i);

      if (joy != NULL) {
        printf("Initialised one gamepad:\n   * %s\n",
            SDL_GameControllerNameForIndex(i));

        m_joysticks.push_back(joy);
        m_joystickValues.push_back(
            std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

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
        SDL_GameControllerClose(m_joysticks[i]);
      }
    }
}

void InputHandler::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_JOYAXISMOTION) {
      int which = event.jaxis.which;

      /*
       * LEFT STICK X-AXIS
       */
      if (event.jaxis.axis == 0) {
        if (event.jaxis.value > m_joystickDeadZone) {
          printf("left stick moving right\n");
          m_joystickValues[which].first->setX(1);
        } else if (event.jaxis.value < -m_joystickDeadZone) {
          printf("left stick moving left\n");
          m_joystickValues[which].first->setX(-1);
        } else {
          m_joystickValues[which].first->setX(0);
        }
      }

      /*
       * LEFT STICK Y-AXIS
       */
      if (event.jaxis.axis == 1) {
        if (event.jaxis.value > m_joystickDeadZone) {
          printf("left stick moving down\n");
          m_joystickValues[which].first->setY(1);
        } else if (event.jaxis.value < -m_joystickDeadZone) {
          printf("left stick moving up\n");
          m_joystickValues[which].first->setY(-1);
        } else {
          m_joystickValues[which].first->setY(0);
        }
      }

      /*
       * RIGHT STICK X-AXIS
       */
      if (event.jaxis.axis == 3) {
        if (event.jaxis.value > m_joystickDeadZone) {
          printf("right stick moving right\n");
          m_joystickValues[which].first->setX(1);
        } else if (event.jaxis.value < -m_joystickDeadZone) {
          printf("right stick moving left\n");
          m_joystickValues[which].first->setX(-1);
        } else {
          m_joystickValues[which].first->setX(0);
        }
      }

      /*
       * RIGHT STICK Y-AXIS
       */
      if (event.jaxis.axis == 4) {
        if (event.jaxis.value > m_joystickDeadZone) {
          printf("right stick moving down\n");
          m_joystickValues[which].first->setY(1);
        } else if (event.jaxis.value < -m_joystickDeadZone) {
          printf("right stick moving up\n");
          m_joystickValues[which].first->setY(-1);
        } else {
          m_joystickValues[which].first->setY(0);
        }
      }
    }
  }
}

int InputHandler::getXAxis(int pad, int stick) const {
  if (m_joystickValues.size() > 0) {
    if (stick == 1) {
      return m_joystickValues[pad].first->getX();
    } else if (stick == 2) {
      return m_joystickValues[pad].second->getX();
    }
  }

  return 0;
}

int InputHandler::getYAxis(int pad, int stick) const {
  if (m_joystickValues.size() > 0) {
    if (stick == 1) {
      return m_joystickValues[pad].first->getY();
    } else if (stick == 2) {
      return m_joystickValues[pad].second->getY();
    }
  }

  return 0;
}
