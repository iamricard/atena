/**
 * Atena Game Engine
 * input-handler.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_INPUT_INPUT_HANDLER_H_
#define LIB_INPUT_INPUT_HANDLER_H_

#include <SDL2/SDL.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "atena/input/event.h"
#include "atena/math/vector-2d.h"

class InputHandler {
 public:
  static InputHandler* Instance() {
    if (instance == 0) {
      instance = new InputHandler();
    }
    return instance;
  }

  void Init();
  void Update();
  void Clean();
  void On(Event event_name, std::function<void()> handler);

  int get_joystick_pos_x(int pad, int stick) const;
  int get_joystick_pos_y(int pad, int stick) const;
  bool is_initialized() { return are_joysticks_initialised; }

 private:
  InputHandler() : joystick_dead_zone(10000) {}
  ~InputHandler() {}

  std::multimap<Event, std::function<void()>> event_handlers;
  std::vector<SDL_GameController*> joysticks;
  std::vector<std::pair<Vector2D*, Vector2D*>> joysticks_values;
  bool are_joysticks_initialised;
  int joystick_dead_zone;

  static InputHandler* instance;
};

typedef InputHandler AGEInput;

#endif  // LIB_INPUT_INPUT_HANDLER_H_
