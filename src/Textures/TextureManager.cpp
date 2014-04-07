// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include "./TextureManager.h"

TextureManager::TextureManager(SDL_Renderer* ren) {
    g_Renderer = ren;
}

void TextureManager::render() {
    for (unsigned int i = 0; i != texturesVector.size(); i++) {
    // TODO: this loop does not feel right either
        if (!texturesVector[i].info == NULL) {
            printf("%s\n", json_dumps(texturesVector[i].info, JSON_INDENT(2)));
        } else {
            printf("No JSON for texture: %s\n", texturesVector[i].key);
        }
    }
}

void TextureManager::loadTexture(char const *key,
                                 char const *pathJSON,
                                 char const *pathIMG) {
    json_t *tmpJSON = NULL;
    SDL_Texture *tmpTex = NULL;
    Texture t;

    tmpJSON = loadJSON(pathJSON);
    tmpTex = loadImage(pathIMG);

    t.key = key;
    t.info = tmpJSON;
    t.texture = tmpTex;

    texturesVector.push_back(t); // TODO: This just does not feel right, AT ALL.
}

SDL_Texture* TextureManager::loadImage(char const *path) {
    SDL_Texture* tmpTexture = NULL;
    SDL_Surface* tmpSurface = NULL;

    tmpSurface = IMG_Load(path);

    if (tmpSurface == NULL) {
        printf("Error loading image %s: %s\n",
                path, IMG_GetError());

    } else {
        tmpTexture = SDL_CreateTextureFromSurface(g_Renderer, tmpSurface);

        if (tmpTexture == NULL) {
            printf("Error creating texture from %s: %s\n",
                    path, IMG_GetError());
        }

        SDL_FreeSurface(tmpSurface);

        // tmpSurface = NULL;
    }

    return tmpTexture;
}

json_t* TextureManager::loadJSON(char const *path) {
    json_t *root = NULL;

    if (FILE* p_inputFile = fopen(path, "r")) {
        printf("File exists");
        json_t *jsonFile;
        json_error_t *error;

        jsonFile = json_loadf(p_inputFile, 0, error);
        root = json_object_get(jsonFile, "frames");

        fclose(p_inputFile);
    } else {
        printf("Error loading json %s\n", path);

        return NULL;
    }

    return root;
}
