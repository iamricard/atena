/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class GameObject {
 public:
     GameObject(std::string f_key, std::string t_key,
                int frames,
                int dstX, int dstY);
    ~GameObject() {}

 private:
    int x;
    int y;
    int frames;
    std::string texture_key;
    std::string frame_key;
};

#endif
