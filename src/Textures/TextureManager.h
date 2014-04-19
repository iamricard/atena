/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jansson.h>

#include <unordered_map>
#include <string>
#include <cstdio>

#include "./Texture.h"

class TextureManager {
 public:
     TextureManager() {}
    ~TextureManager() {}

    bool load(std::string key, char const *pathJSON, char const *pathIMG,
              SDL_Renderer *ren);

    void drawFrame(std::string texture_key,
                   int x, int y,
                   int witdh, int height,
                   int row, int frame);
    void drawKey(std::string texture_key, std::string frame_key);
    void draw(std::string texture_key,
              int x, int y,
              int width, int height);

 private:
    SDL_Texture* loadImage(char const *path, SDL_Renderer *ren);
    json_t* loadJSON(char const *path);

    std::unordered_map <std::string, Texture*> textures;
};

#endif
