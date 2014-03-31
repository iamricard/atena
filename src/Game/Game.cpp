// Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]

#include <cstdio>
#include "./Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width,
                                    int height, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        printf("SDL_Init success\n");

        win = SDL_CreateWindow(title,
                xpos, ypos,
                width, height,
                flags);

        if (win != 0) {
            printf("SDL_CreateWindow success\n");

            renderer = SDL_CreateRenderer(win, -1, 0);

            if (renderer != 0) {
                printf("SDL_CreateRenderer success\n");
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            } else {
                printf("SDL_CreateRenderer error\n");
                return false;
            }
        } else {
            printf("SDL_CreateWindow error\n");
            return false;
        }
    } else {
        printf("SDL_Init error\n");
        return false;
    }

    printf("Init succes\n");
    m_bRunning = true;

    return true;
}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    printf("cleaning game\n");
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;

            default:
                break;
        }
    }
}
