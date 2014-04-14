/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __SpriteManager__
#define __SpriteManager__

#include <SDL2/SDL.h>

#include <vector>
#include <string>

#include "./Sprite.h"

class SpriteManager {
 public:
     SpriteManager() {}
    ~SpriteManager() {}

    void renderSprites(SDL_Renderer* ren);
    Sprite* addSprite(std::string k, Texture *t, int x, int y);

 private:
    std::vector <Sprite*> spritesVector;
};

#endif
