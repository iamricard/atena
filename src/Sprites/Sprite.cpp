/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Sprite.h"

Sprite::Sprite(std::string key, Texture *texture,
               int dstX, int dstY) {
    m_Texture = texture;
    std::vector<int> frame = m_Texture->getFrame(key);
    m_srcRect.x = frame[0];
    m_srcRect.x = frame[1];
    m_dstRect.x = dstX;
    m_dstRect.y = dstY;
    m_srcRect.w = m_dstRect.w = frame[2];
    m_srcRect.h = m_dstRect.h = frame[3];
}

void Sprite::render(SDL_Renderer *ren) {
    SDL_RenderCopy(ren, m_Texture->getTexture(), &m_srcRect, &m_dstRect);
}
