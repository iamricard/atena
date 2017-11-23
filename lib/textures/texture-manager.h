/**
 * Atena Game Engine
 * texture-manager.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef __TextureManager__
#define __TextureManager__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jansson.h>
#include <unordered_map>
#include <string>
#include <cstdio>

#include "./texture.h"

class TextureManager {
public:
  static TextureManager* Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new TextureManager();
    }

    return s_pInstance;
  }

  bool load(std::string key, std::string pathJSON, std::string pathIMG,
            SDL_Renderer *ren);
  bool load(std::string key, std::string pathIMG,
            SDL_Renderer *ren);

  void drawFrame(std::string texture_key, std::string frame_key,
                 int x, int y,
                 SDL_Renderer *pRenderer);
  void drawFrame(std::string texture_key,
                 int x, int y,
                 int witdh, int height,
                 int row, int frame,
                 SDL_Renderer *pRenderer);
  void draw(std::string texture_key,
            int x, int y,
            int width, int height,
            SDL_Renderer *pRenderer);

private:
  TextureManager() {}
  ~TextureManager() {}

  SDL_Texture* loadImage(char const *path, SDL_Renderer *ren);
  json_t* loadJSON(char const *path);

  std::unordered_map <std::string, Texture*> m_textureMap;

  static TextureManager* s_pInstance;
};

typedef TextureManager AGETextures;

#endif
