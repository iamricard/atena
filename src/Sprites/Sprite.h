/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

// Sprite methods and attributes

#ifndef __Sprite__
#define __Sprite__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <cstdio>
#include <string>
#include <vector>

#include "../Textures/Texture.h"

class Sprite {
 public:
     Sprite(std::string key, Texture *texture,
            int dstX, int dstY);
    ~Sprite() {}

    void render(SDL_Renderer* ren);

 private:
    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;
    Texture *m_Texture;
    std::string m_key;
};

#endif
