/**
 * Atena Game Engine
 * GameObjectFactory.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>
#include "./GameObject.h"

class Creator {
 public:
    virtual GameObject* createGameObject() const = 0;
    virtual ~Creator() {}
};

class GameObjectFactory {
 public:
    GameObjectFactory() {}
    ~GameObjectFactory() {}

    bool registerType(std::string typeID, Creator* pCreator) {
        std::map<std::string, Creator*>::iterator it = m_creators.find(typeID);

        if (it != m_creators.end()) {
            delete pCreator;
        }

        m_creators[typeID] = pCreator;

        return true;
    }

    GameObject* create(std::string typeID) {
        std::map<std::string, Creator*>::iterator it = m_creators.find(typeID);

        if (it == m_creators.end()) {
            printf("Type %s not found\n", typeID.c_str());
            return NULL;
        }

        Creator* pCreator = (*it).second;
        return pCreator->createGameObject();
    }

 private:
    std::map<std::string, Creator*> m_creators;
};

#endif
