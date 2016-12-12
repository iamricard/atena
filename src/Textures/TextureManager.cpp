/**
 * Atena Game Engine
 * TextureManager.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

void TextureManager::drawFrame(std::string texture_key, std::string frame_key,
                               int x, int y,
                               SDL_Renderer* pRenderer) {
  std::vector<int> coords = m_textureMap[texture_key]->getFrame(frame_key);

  if (!coords.empty()) {
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    srcRect.x = coords[0];
    srcRect.y = coords[1];
    srcRect.w = dstRect.w = coords[2];
    srcRect.h = dstRect.h = coords[3];
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(pRenderer,
                     m_textureMap[texture_key]->getTexture(),
                     &srcRect, &dstRect,
                     0, 0,
                     SDL_FLIP_NONE);
  }
}

void TextureManager::drawFrame(std::string texture_key,
                               int x, int y,
                               int width, int height,
                               int row, int frame,
                               SDL_Renderer* pRenderer) {
  SDL_Rect srcRect;
  SDL_Rect dstRect;

  srcRect.x = width * frame;
  srcRect.y = height * (row - 1);
  srcRect.w = dstRect.w = width;
  srcRect.h = dstRect.h = height;
  dstRect.x = x;
  dstRect.y = y;

  SDL_RenderCopyEx(pRenderer,
                   m_textureMap[texture_key]->getTexture(),
                   &srcRect, &dstRect,
                   0, 0,
                   SDL_FLIP_NONE);
}

void TextureManager::draw(std::string texture_key,
                          int x, int y,
                          int width, int height,
                          SDL_Renderer* pRenderer) {
  SDL_Rect srcRect;
  SDL_Rect dstRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = dstRect.w = width;
  srcRect.h = dstRect.h = height;
  dstRect.x = x;
  dstRect.y = y;

  SDL_RenderCopyEx(pRenderer,
                   m_textureMap[texture_key]->getTexture(),
                   &srcRect, &dstRect,
                   0, 0,
                   SDL_FLIP_NONE);
}

bool TextureManager::load(std::string key, std::string pathIMG,
                          SDL_Renderer *ren) {
  SDL_Texture *tmpTex = NULL;
  tmpTex = loadImage(pathIMG.c_str(), ren);

  Texture *t = new Texture(tmpTex);

  m_textureMap[key] = t;

  return true;
}

bool TextureManager::load(std::string key,
                          std::string pathJSON,
                          std::string pathIMG,
                          SDL_Renderer *ren) {
  json_t *tmpJSON = NULL;
  SDL_Texture *tmpTex = NULL;

  tmpTex = loadImage(pathIMG.c_str(), ren);
  tmpJSON = loadJSON(pathJSON.c_str());

  Texture* t = new Texture(tmpTex, tmpJSON);

  m_textureMap[key] = t;

  return true;
}

SDL_Texture* TextureManager::loadImage(char const *path, SDL_Renderer *ren) {
  SDL_Texture* tmpTexture = NULL;
  SDL_Surface* tmpSurface = NULL;

  tmpSurface = IMG_Load(path);

  if (tmpSurface == NULL) {
    printf("Error loading image %s: %s\n",
            path, IMG_GetError());

  } else {
    printf("Image %s loaded\n", path);
    tmpTexture = SDL_CreateTextureFromSurface(ren, tmpSurface);

    if (tmpTexture == NULL) {
      printf("Error creating texture from %s: %s\n",
              path, IMG_GetError());
    }

    printf("Texture %s loaded\n", path);
    SDL_FreeSurface(tmpSurface);
  }

  return tmpTexture;
}

json_t* TextureManager::loadJSON(char const *path) {
  json_t *root = NULL;

  if (FILE* p_inputFile = fopen(path, "r")) {
    printf("File exists\n");
    json_t *jsonFile = NULL;
    json_error_t *error = NULL;

    jsonFile = json_loadf(p_inputFile, 0, error);
    root = json_object_get(jsonFile, "frames");

    fclose(p_inputFile);
  } else {
    printf("Error loading json %s\n", path);

    return root;
  }

  return root;
}
