/**
 * Atena Game Engine
 * texture-manager.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_TEXTURES_TEXTURE_MANAGER_H_
#define LIB_TEXTURES_TEXTURE_MANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jansson.h>
#include <cstdio>
#include <string>
#include <unordered_map>

#include "./texture.h"

class TextureManager {
 public:
  static TextureManager *Instance() {
    if (s_pInstance == 0) {
      s_pInstance = new TextureManager();
    }

    return s_pInstance;
  }

  bool Load(std::string key, std::string pathJSON, std::string pathIMG,
            SDL_Renderer *ren);
  bool Load(std::string key, std::string pathIMG, SDL_Renderer *ren);

  void DrawFrame(std::string texture_key, std::string frame_key, int x, int y,
                 SDL_Renderer *pRenderer);
  void DrawFrame(std::string texture_key, int x, int y, int witdh, int height,
                 int row, int frame, SDL_Renderer *pRenderer);
  void Draw(std::string texture_key, int x, int y, int width, int height,
            SDL_Renderer *pRenderer);

 private:
  TextureManager() {}
  ~TextureManager() {}

  SDL_Texture *LoadImage(char const *path, SDL_Renderer *ren);
  json_t *LoadJson(char const *path);

  std::unordered_map<std::string, Texture *> m_textureMap;

  static TextureManager *s_pInstance;
};

typedef TextureManager AGETextures;

#endif  // LIB_TEXTURES_TEXTURE_MANAGER_H_
