/**
 * Atena Game Engine
 * entity-config.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_ENTITIES_ENTITY_CONFIG_H_
#define LIB_ENTITIES_ENTITY_CONFIG_H_

#include <string>

class EntityConfig {
 public:
  EntityConfig(std::string texture_key, float x, float y, int w, int h)
      : x(x),
        y(y),
        width(w),
        height(h),
        json(false),
        texture_key(texture_key),
        frame_key("") {}

  EntityConfig(std::string texture_key, std::string frame_key, float x, float y)
      : x(x),
        y(y),
        width(0),
        height(0),
        json(true),
        texture_key(texture_key),
        frame_key(frame_key) {}

  ~EntityConfig();

  int get_x_position() const { return x; }
  int get_y_position() const { return y; }

  int get_width() const { return width; }
  int get_height() const { return height; }

  bool IsJson() const { return json; }

  std::string get_texture_key() const { return texture_key; }
  std::string get_frame_key() const { return frame_key; }

 private:
  int x;
  int y;

  int width;
  int height;

  bool json;

  std::string texture_key;
  std::string frame_key;
};

#endif  // LIB_ENTITIES_ENTITY_CONFIG_H_
