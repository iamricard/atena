// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

// Sprite methods and attributes

#ifndef __Sprite__
#define __Sprite__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Sprite {
 public:
     Sprite();
    ~Sprite() {}

    void render();
 private:
    SDL_Rect m_srcRect;
    SDL_Rect m_dstRect;
};

#endif
