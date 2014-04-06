// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#ifndef __Texture__
#define __Texture__

#include <SDL2/SDL.h>
#include <jansson.h>

#include <iostream>

struct Texture {
    char const *key = NULL;
    SDL_Texture *texture = NULL;
    json_t *info = NULL;
};

#endif
