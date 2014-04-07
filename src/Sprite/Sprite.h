// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

// Sprite methods and attributes

#ifndef __Sprite__
#define __Sprite__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Textures/Texture.h"

class Sprite {
 public:
     Sprite(char *key, Texture *texture);
    ~Sprite() {}

    void render();
 private:
    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;
    Texture &m_texture;
    char &m_key;
};

#endif
