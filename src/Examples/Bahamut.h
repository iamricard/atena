/**
 * Atena Game Engine
 * Bahamut.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "../Core/GameObject.h"
#include "../Utils/LoaderParams.h"
#include "../Core/InputHandler.h"

class Bahamut : public GameObject {
 public:
    Bahamut(const LoaderParams* pParams):
        GameObject(pParams) {}
    ~Bahamut() {}

    void draw(SDL_Renderer *ren);
    void update();
    void clean();

 private:
    void handleInput();
};
