// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>

#include <vector>

#include "../Sprite/Sprite.h"
#include "../Textures/TextureManager.h"

class Game {
 public:
     Game(const char* title,
            int xpos, int ypos,
            int width, int height,
            int flags);
    ~Game() {}

    // bool init(const char* title,
    //         int xpos, int ypos,
    //         int width, int height,
    //         int flags);

    void addSprite(const char* imgUrl, int x, int y, int w, int h);

    void render();
    void update();
    void handleEvents();
    void clean();

    SDL_Renderer* getRenderer();

    bool running() { return m_Running; }

 private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_Running;
};

#endif
