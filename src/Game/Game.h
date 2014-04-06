// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <vector>

#include "../Sprite/Sprite.h"
#include "../Textures/TextureManager.h"

class Game {
 public:
     Game() {}
    ~Game() {}

    bool init(const char* title,
            int xpos, int ypos,
            int width, int height,
            int flags);

    void addSprite(const char* imgUrl, int x, int y, int w, int h);

    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_Running; }

    TextureManager* textures = NULL;

 private:
    SDL_Window* m_pWindow = NULL;
    SDL_Renderer* m_pRenderer = NULL;

    bool m_Running;
};

#endif
