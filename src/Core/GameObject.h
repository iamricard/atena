/**
 * Atena Game Engine
 * GameObject.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __GameObject__
#define __GameObject__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "../Textures/TextureManager.h"
#include "../Utils/LoaderParams.h"
#include "../Utils/Vector2D.h"

class GameObject {
 public:
    virtual void draw(SDL_Renderer *ren)=0;
    virtual void update()=0;
    virtual void clean()=0;

 protected:
    GameObject(const LoaderParams *pParams);
    virtual ~GameObject() {}

    int m_x;
    int m_y;

    int m_width;
    int m_height;

    int m_row;
    int m_frame;

    std::string m_textureKey;
    std::string m_frameKey;
};

#endif
