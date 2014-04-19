/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./GameObject.h"

GameObject::GameObject(std::string f_key,
                       std::string t_key,
                       int frame_count,
                       int dstX, int dstY)
                    : x(dstX), y(dstY),
                      frames(frame_count),
                      texture_key(t_key),
                      frame_key(f_key) {}
