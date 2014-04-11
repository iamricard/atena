/**
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#include "./Sprite.h"

Sprite::Sprite(char const *key, Texture *texture, int dstX, int dstY)
                : m_key(key), m_Texture(texture) {
        size_t i;

        m_dstRect.x = dstX;
        m_dstRect.y = dstY;

        for (i = 0; i < json_array_size(m_Texture->info); i++) {
            char const *name = NULL;
            json_t *data = NULL;

            data = json_array_get(m_Texture->info, i);
            name = json_string_value(json_object_get(data, "filename"));

            if (strcmp(name, key)) {
                json_t *rects = NULL;

                rects = json_object_get(data, "frame");
                m_srcRect.x =
                    static_cast<int>
                        (json_number_value(json_object_get(rects, "x")));
                m_srcRect.y =
                    static_cast<int>
                        (json_number_value(json_object_get(rects, "y")));

                m_dstRect.w = m_srcRect.w =
                    static_cast<int>
                        (json_number_value(json_object_get(rects, "w")));
                m_dstRect.h = m_srcRect.h =
                    static_cast<int>
                        (json_number_value(json_object_get(rects, "h")));
            }
        }

        printf("%s", json_dumps(texture->info, 0));
}

void Sprite::render(SDL_Renderer *ren) {
    SDL_RenderCopy(ren, m_Texture->texture, &m_srcRect, &m_dstRect);
}
