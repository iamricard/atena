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

#include "./GameObject.h"
#include "./InputHandler.h"

class GameObject;

class Game {
 public:
     Game();
    ~Game() {}

    bool init(const char* title,
            int xpos, int ypos,
            int width, int height,
            int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit() { m_Running = false; }

    void drawGameObjects();

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    bool running() { return m_Running; }

 private:
    static Game *s_pInstance;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    bool m_Running;

    std::vector<GameObject*> m_gameObjects;
};

typedef Game AGEGame;
#endif
