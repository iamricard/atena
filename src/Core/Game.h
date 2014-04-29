/**
 * Atena Game Engine
 * Game.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __Game__
#define __Game__

#ifdef __GNUC__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <vector>

#include "./InputHandler.h"
#include "./GameObjectFactory.h"

class GameObject;

class Game {
 public:
     Game();
    ~Game() {}

    bool init(const char *title,
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
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    bool m_Running;
    static bool instantiated_;

    GameObjectFactory *m_objectFactory;

    std::vector<GameObject*> m_gameObjects;
};

#endif
