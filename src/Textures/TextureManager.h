// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jansson.h>

#include <iostream>

#include "./Texture.cpp"

#include <string>
#include <cstdio>
#include <vector>


class TextureManager {
 public:
     TextureManager(SDL_Renderer *ren);
    ~TextureManager();

    void render();
    void loadTexture(char const *key, char const *pathJSON, char const *pathIMG);

    SDL_Texture* loadImage(char const *path);
    json_t* loadJSON(char const *path);
 private:
    SDL_Renderer *g_Renderer;
    std::vector <Texture> texturesVector; // TODO: This shit doesn't feel right
};

#endif
