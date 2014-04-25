/**
 * Atena Game Engine
 * Sprite.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "../Core/GameObjectFactory.h"
#include "../Core/GameObject.h"
#include "../Utils/LoaderParams.h"
#include "../Core/InputHandler.h"

class GameObject;

class Sprite : public GameObject {
 public:
    Sprite() : GameObject() {}
    ~Sprite() {}

    void load(const LoaderParams* pParams);
    void draw(SDL_Renderer *ren);
    void update();
    void clean();

 private:
    void handleInput();
};

class SpriteCreator : public Creator {
    GameObject* createGameObject() const {
        return new Sprite();
    }
};
