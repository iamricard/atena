/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>

#include <vector>

#include "../Textures/TextureManager.h"
#include "../Textures/Texture.h"
#include "../Sprites/SpriteManager.h"
#include "../Sprites/Sprite.h"

class Game {
 public:
     Game(const char* title,
            int xpos, int ypos,
            int width, int height,
            int flags);
    ~Game() {}

    void render();
    void update();
    void handleEvents();
    void clean();

    void enableSprites();
    void enableTextures();

    Sprite* addSprite(std::string k, Texture *t, int x, int y);

    Texture* loadTexture(std::string key,
                         char const *pathJSON,
                         char const *pathIMG,
                         SDL_Renderer *ren);
    Texture* getTexture(char const *key);

    SDL_Renderer* getRenderer() { return m_pRenderer; }
    bool running() { return m_Running; }

 private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    SpriteManager* m_SpriteMgr;
    TextureManager* m_TextureMgr;

    bool m_Running;
    bool b_Sprites;
    bool b_Textures;
};

#endif
