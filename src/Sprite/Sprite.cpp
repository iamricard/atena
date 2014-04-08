// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include "./Sprite.h"

Sprite::Sprite(char *key, Texture *texture, int dstX, int dstY)
                : m_key(*key), m_texture(*texture) {
        m_dstRect.x = dstX;
        m_dstRect.y = dstY;

        printf("%s", json_dumps(texture->info, 0));
}

void Sprite::render() {
    // TODO(rcsole): Implement
}
