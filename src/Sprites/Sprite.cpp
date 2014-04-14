/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Sprite.h"

Sprite::Sprite(std::string key, Texture *texture,
               int dstX, int dstY) {
    m_Texture = texture;
    std::vector<int> frame = m_Texture->getFrame(key);
    m_srcRect.x = frame[0];
    m_srcRect.y = frame[1];
    m_dstRect.x = dstX;
    m_dstRect.y = dstY;
    m_srcRect.w = m_dstRect.w = frame[2];
    m_srcRect.h = m_dstRect.h = frame[3];

    printf("Source x: %i\nSource y: %i\nSource w: %i\nSource h: %i\n",
            m_srcRect.x, m_srcRect.y, m_srcRect.w, m_srcRect.h);
    printf("Dest x: %i\nDest y: %i\nDest w: %i\nDest h: %i\n",
            m_dstRect.x, m_dstRect.y, m_dstRect.w, m_dstRect.h);
}

void Sprite::render(SDL_Renderer *ren) {
    SDL_RenderCopy(ren, m_Texture->getTexture(), &m_srcRect, &m_dstRect);
}
