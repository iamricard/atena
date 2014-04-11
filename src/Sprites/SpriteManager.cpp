/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./SpriteManager.h"

void SpriteManager::renderSprites(SDL_Renderer* ren) {
    for (unsigned int i = 0; i != spritesVector.size(); i++) {
        spritesVector[i]->render(ren);
    }
}

// TODO(rcsole): Maybe this should return the sprite object
void SpriteManager::addSprite(char const *k, Texture *t, int x, int y) {
    Sprite *s = new Sprite(k, t, x, y);
    spritesVector.push_back(s);
    printf("Sprite %s successfully added\n", k);
}
