/**
 * Atena Game Engine
 * entity-factory.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#include <string>
#include <map>
#include "./base-entity.h"

class EntityFactory {
public:
  EntityFactory() {}
  ~EntityFactory() {}

  bool RegisterEntityBuilder(std::string typeID, EntityBuilder* entity_builder) {
    std::map<std::string, EntityBuilder*>::iterator it = entity_builders.find(typeID);
    if (it != entity_builders.end()) {
      delete entity_builder;
    }
    entity_builders[typeID] = entity_builder;
    return true;
  }

  BaseEntity* create(std::string typeID) {
    std::map<std::string, EntityBuilder*>::iterator it = entity_builders.find(typeID);

    if (it == entity_builders.end()) {
      printf("Type %s not found\n", typeID.c_str());
      return NULL;
    }

    EntityBuilder* entity_builder = (*it).second;
    return entity_builder->Build();
  }

private:
  std::map<std::string, EntityBuilder*> entity_builders;
};
