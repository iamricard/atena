/**
 * Atena Game Engine
 * Game.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>

#include <vector>

#include "../Textures/TextureManager.h"
#include "./InputHandler.h"

class Game {
 public:
    static Game* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new Game();
        }

        return s_pInstance;
    }

    bool init(const char* title,
            int xpos, int ypos,
            int width, int height,
            int flags);
    void render();
    void update();
    void handleEvents();
    void clean();

    void enableSprites();
    void enableTextures();

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    bool running() { return m_Running; }

 private:
     Game();
    ~Game() {}
    static Game *s_pInstance;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_Running;
};

typedef Game AGEGame;
#endif
