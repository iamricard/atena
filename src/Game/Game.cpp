/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include <cstdio>

#include "./Game.h"

Game::Game(const char* title, int xpos, int ypos, int width,
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
    if (b_Sprites)
        m_SpriteMgr->renderSprites(m_pRenderer);
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

void Game::enableSprites() {
    b_Sprites = true;
    m_SpriteMgr = new SpriteManager();
}

void Game::enableTextures() {
    b_Textures = true;
    m_TextureMgr = new TextureManager();
}

Sprite* Game::addSprite(std::string k, Texture *t, int x, int y) {
    Sprite* s = NULL;
    if (b_Sprites) {
        s = m_SpriteMgr->addSprite(k, t, x, y);
        return s;
    } else {
        printf("Sprites disabled, make sure you did game->enableSprites()");
        return s;
    }
}

Texture* Game::loadTexture(std::string key,
                            char const *pathJSON,
                            char const *pathIMG,
                            SDL_Renderer *ren) {
    Texture* t = NULL;
    if (b_Textures) {
        t = m_TextureMgr->loadTexture(key, pathJSON, pathIMG, ren);
        return t;
    } else {
        printf("Textures disabled, make sure you did game->enableTextures()");
        return t;
    }
}

Texture* Game::getTexture(char const *key) {
    Texture* t = NULL;
    if (b_Textures) {
        t = m_TextureMgr->getTexture(key);
        return t;
    } else {
        printf("Textures disabled, make sure you did game->enableTextures()");
        return t;
    }
}
