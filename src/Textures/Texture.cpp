/**
 * Atena Game Engine
 * Texture.cpp
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Texture.h"

Texture::Texture(SDL_Texture *t, json_t *json) {
    size_t i;

    for (i = 0; i < json_array_size(json); i++) {
        json_t *frame;
        json_t *coords;
        std::string key;
        std::vector<int> xywh;

        frame = json_array_get(json, i);
        key = std::string(
            json_string_value(json_object_get(frame, "filename")));
        coords = json_object_get(frame, "frame");

        xywh
            .push_back(static_cast<int>
                (json_number_value(json_object_get(coords, "x"))));
        xywh
            .push_back(static_cast<int>(
                json_number_value(json_object_get(coords, "y"))));
        xywh
            .push_back(static_cast<int>(
                json_number_value(json_object_get(coords, "w"))));
        xywh
            .push_back(static_cast<int>(
                json_number_value(json_object_get(coords, "h"))));

        frames[key] = xywh;
        xywh.clear();

        printf("%s loaded\n", key.c_str());
    }

    texture = t;
}

std::vector<int> Texture::getFrame(std::string key) {
    std::unordered_map< std::string, std::vector<int> >::iterator it
                                                        = frames.find(key);

    if (it == frames.end()) {
        return std::vector<int>();
    } else {
        return frames[key];
    }
}

SDL_Texture* Texture::getTexture() {
    return texture;
}
