/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __Texture__
#define __Texture__

#include <SDL2/SDL.h>
#include <jansson.h>

class Texture {
 public:
     Texture(char const *k, SDL_Texture *t, json_t *i)
        : key(k), texture(t), info(i) {}
    ~Texture();

    const char* getKey() { return key; }
    SDL_Texture* getTexture() { return texture; }
    json_t* getInfo() { return info; }

 private:
    char const *key;
    SDL_Texture *texture;
    json_t *info;
};

#endif
