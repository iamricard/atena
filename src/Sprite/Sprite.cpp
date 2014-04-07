// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include "./Sprite.h"

Sprite::Sprite(char *key, Texture *texture) : m_key(*key), m_texture(*texture) {
    // TODO(rcsole)
    m_texture = *texture;
    m_key = *key;
}

void Sprite::render() {
    // TODO(rcsole): Implements
}
