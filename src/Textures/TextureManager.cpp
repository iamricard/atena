// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include "./TextureManager.h"

TextureManager::TextureManager(SDL_Renderer* ren) {
    g_Renderer = ren;
}

void TextureManager::render() {
    printf("Rendering textures\n");

    // this loop does not feel right either
    // for (unsigned int i = 0; i != texturesVector.size(); i++) {
    // this looks better?
    for (unsigned int i = 0; i < texturesVector.size(); i++) {
        printf("Looping\n");
        // if (!t.info == 0) {
        //     printf("%s\n", json_dumps(t.info, JSON_INDENT(2)));
        // } else {
        //     printf("No JSON for texture: %s\n", t.key);
        // }
    }
}

void TextureManager::loadTexture(char const *key,
                                 char const *pathJSON,
                                 char const *pathIMG) {
    printf("Loading texture\n");
    json_t *tmpJSON = NULL;
    SDL_Texture *tmpTex = NULL;
    Texture t;

    tmpJSON = loadJSON(pathJSON);
    tmpTex = loadImage(pathIMG);

    t.key = key;
    t.info = tmpJSON;
    t.texture = tmpTex;

    // TODO(rcsole): This just does not feel right, AT ALL.
    texturesVector.push_back(t);
    printf("Texture loaded\n");
    printf("Number of textures: %zu\n", texturesVector.size());
}

SDL_Texture* TextureManager::loadImage(char const *path) {
    SDL_Texture* tmpTexture = NULL;
    SDL_Surface* tmpSurface = NULL;

    tmpSurface = IMG_Load(path);

    if (tmpSurface == NULL) {
        printf("Error loading image %s: %s\n",
                path, IMG_GetError());

    } else {
        printf("Image %s loaded\n", path);
        tmpTexture = SDL_CreateTextureFromSurface(g_Renderer, tmpSurface);

        if (tmpTexture == NULL) {
            printf("Error creating texture from %s: %s\n",
                    path, IMG_GetError());
        }

        printf("Texture %s loaded\n", path);
        SDL_FreeSurface(tmpSurface);

        // tmpSurface = NULL;
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

// Texture TextureManager::getTexture(char const *key) {
//     Texture t;
//     for (unsigned int i = 0; i != texturesVector.size(); i++) {
//         if (strcmp(texturesVector[i].key, key)) {
//             t = texturesVector[i];
//             return t;
//         } else {
//             printf("No texture found with key: %s\n", key);
//             return t;
//         }
//     }
// }

void TextureManager::getTextureJSON(char const *key) {
    printf("Getting JSON\n");
    for (unsigned int i = 0; i != texturesVector.size(); i++) {
        printf("Looping\n");
        printf("%s\n", texturesVector[i].key);
        if (strcmp(texturesVector[i].key, key) == 0) {
            printf("%s\n", json_dumps(texturesVector[i].info, 0));
        } else {
            printf("No texture found with key: %s\n", key);
        }
    }
}
