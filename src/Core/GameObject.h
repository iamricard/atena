/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdio>
#include <string>
#include <vector>

#include "../Textures/Texture.h"

class GameObject {
 public:
     GameObject(std::string key, Texture *texture,
            int dstX, int dstY);
    ~GameObject() {}

 private:
    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;
    std::string texture_key;
    std::string frame_key;
};

#endif
