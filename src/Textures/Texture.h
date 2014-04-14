/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __Texture__
#define __Texture__

#include <SDL2/SDL.h>
#include <jansson.h>

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Texture {
 public:
     Texture(SDL_Texture *t, json_t *json);
    ~Texture();

    std::vector<int> getFrame(std::string key);
    SDL_Texture* getTexture();

 private:
    SDL_Texture *texture;
    std::unordered_map<std::string, std::vector<int>> frames;
};

#endif
