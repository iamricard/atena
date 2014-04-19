/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./GameObject.h"

GameObject::GameObject(std::string f_key,
                       std::string t_key,
                       int dstX, int dstY) {
    frame_key = f_key;
    texture_key = texture_key;
    // m_srcRect.x = frame[0];
    // m_srcRect.y = frame[1];
    m_dstRect.x = dstX;
    m_dstRect.y = dstY;
    // m_srcRect.w = m_dstRect.w = frame[2];
    // m_srcRect.h = m_dstRect.h = frame[3];
    //
    // @todo(rcsole): get src x, y, w, h coords from texture manager
    //
}
