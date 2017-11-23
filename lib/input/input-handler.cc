/**
 * Atena Game Engine
 * input-handler.cc
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include "atena/input/input-handler.h"

InputHandler* InputHandler::instance = 0;

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

        joysticks.push_back(joy);
        joysticks_values.push_back(
            std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));

      } else {
        printf("%s", SDL_GetError());
      }
    }

    SDL_JoystickEventState(SDL_ENABLE);
    are_joysticks_initialised = true;

    printf("Initialised %zu joystick(s)\n", joysticks.size());
  } else {
    are_joysticks_initialised = false;
  }
}

void InputHandler::clean() {
  if (are_joysticks_initialised) {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
      SDL_GameControllerClose(joysticks[i]);
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
        if (event.jaxis.value > joystick_dead_zone) {
          printf("left stick moving right\n");
          joysticks_values[which].first->set_x_position(1);
        } else if (event.jaxis.value < -joystick_dead_zone) {
          printf("left stick moving left\n");
          joysticks_values[which].first->set_x_position(-1);
        } else {
          joysticks_values[which].first->set_x_position(0);
        }
      }

      /*
       * LEFT STICK Y-AXIS
       */
      if (event.jaxis.axis == 1) {
        if (event.jaxis.value > joystick_dead_zone) {
          printf("left stick moving down\n");
          joysticks_values[which].first->set_y_position(1);
        } else if (event.jaxis.value < -joystick_dead_zone) {
          printf("left stick moving up\n");
          joysticks_values[which].first->set_y_position(-1);
        } else {
          joysticks_values[which].first->set_y_position(0);
        }
      }

      /*
       * RIGHT STICK X-AXIS
       */
      if (event.jaxis.axis == 3) {
        if (event.jaxis.value > joystick_dead_zone) {
          printf("right stick moving right\n");
          joysticks_values[which].first->set_x_position(1);
        } else if (event.jaxis.value < -joystick_dead_zone) {
          printf("right stick moving left\n");
          joysticks_values[which].first->set_x_position(-1);
        } else {
          joysticks_values[which].first->set_x_position(0);
        }
      }

      /*
       * RIGHT STICK Y-AXIS
       */
      if (event.jaxis.axis == 4) {
        if (event.jaxis.value > joystick_dead_zone) {
          printf("right stick moving down\n");
          joysticks_values[which].first->set_y_position(1);
        } else if (event.jaxis.value < -joystick_dead_zone) {
          printf("right stick moving up\n");
          joysticks_values[which].first->set_y_position(-1);
        } else {
          joysticks_values[which].first->set_y_position(0);
        }
      }
    }
  }
}

int InputHandler::get_x_positionAxis(int pad, int stick) const {
  if (joysticks_values.size() > 0) {
    if (stick == 1) {
      return joysticks_values[pad].first->get_x_position();
    } else if (stick == 2) {
      return joysticks_values[pad].second->get_x_position();
    }
  }

  return 0;
}

int InputHandler::get_y_positionAxis(int pad, int stick) const {
  if (joysticks_values.size() > 0) {
    if (stick == 1) {
      return joysticks_values[pad].first->get_y_position();
    } else if (stick == 2) {
      return joysticks_values[pad].second->get_y_position();
    }
  }

  return 0;
}
