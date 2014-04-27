/**
 * Atena Game Engine
 * GameObject.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __GameObject__
#define __GameObject__

#ifdef __GNUC__
 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>
#else
 #include <SDL.h>
 #include <SDL_image.h>
#endif

#include <string>

#include "../Utils/Vector2D.h"
#include "../Textures/TextureManager.h"
#include "../Utils/LoaderParams.h"

class GameObject {
 public:
    virtual void load(const LoaderParams* pParams)=0;
    virtual void draw(SDL_Renderer *ren)=0;
    virtual void update()=0;
    virtual void clean()=0;

 protected:
    GameObject();
    virtual ~GameObject() {}

    int m_width;
    int m_height;

    int m_row;
    int m_frame;

    bool m_json;

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    std::string m_textureKey;
    std::string m_frameKey;
};

#endif
