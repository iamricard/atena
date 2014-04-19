/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./TextureManager.h"

void TextureManager::drawFrame(std::string texture_key,
               int x, int y,
               int witdh, int height,
               int row, int frame) {
    // @todo(rcsole): implement
}

void drawKey(std::string texture_key, std::string frame_key) {
    // @todo(rcsole): implement
}

void draw(std::string texture_key,
          int x, int y,
          int width, int height) {
    // @todo(rcsole): implement
}

bool TextureManager::load(std::string key,
                          char const *pathJSON,
                          char const *pathIMG,
                          SDL_Renderer *ren) {
    printf("Loading texture\n");
    json_t *tmpJSON = NULL;
    SDL_Texture *tmpTex = NULL;

    tmpTex = loadImage(pathIMG, ren);
    tmpJSON = loadJSON(pathJSON);

    Texture* t = new Texture(tmpTex, tmpJSON);

    textures[key] = t;
    printf("Texture loaded\n");

    return t;
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
