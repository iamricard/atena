/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jansson.h>

#include <vector>
#include <string>
#include <cstdio>

#include "./Texture.h"

class TextureManager {
 public:
     explicit TextureManager(SDL_Renderer *ren);
    ~TextureManager();

    void render();
    void loadTexture(char const *key,
                     char const *pathJSON,
                     char const *pathIMG);

    SDL_Texture* loadImage(char const *path);
    json_t* loadJSON(char const *path);

    Texture* getTexture(char const *key);
    void getTextureJSON(char const *key);

 private:
    // I don't think this needs to be here
    SDL_Renderer *g_Renderer;
    // TODO(rcsole): This shit doesn't feel right
    std::vector <Texture*> texturesVector;
};

#endif
