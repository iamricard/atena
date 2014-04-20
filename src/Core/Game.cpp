/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <cstdio>

#include "./Game.h"

Game* Game::s_pInstance = 0;
Game::Game(): m_pWindow(0), m_pRenderer(0), m_Running(false) {}

bool Game::init(const char* title, int xpos, int ypos, int width,
                                    int height, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        printf("SDL_Init success\n");

        m_pWindow = SDL_CreateWindow(title,
                xpos, ypos,
                width, height,
                flags);

        if (m_pWindow != 0) {
            printf("SDL_CreateWindow success\n");

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                printf("SDL_CreateRenderer success\n");
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

            } else {
                printf("SDL_CreateRenderer error\n");
            }
        } else {
            printf("SDL_CreateWindow error\n");
        }
    } else {
        printf("SDL_Init error\n");
    }

    printf("Init succes\n");
    m_Running = true;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    // @todo(rcsole): this is here for testing purposes, but it is not right
    AGETextures::Instance()->drawFrame("Sprites1",
                                       "bahamut.png",
                                       100, 100,
                                       m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
    printf("Cleaning game\n");
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_Running = false;
                break;

            default:
                break;
        }
    }
}
