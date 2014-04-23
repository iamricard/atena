/**
 * Atena Game Engine
 * LoaderParams.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

#ifndef __LOADERPARAMS__
#define __LOADERPARAMS__

class LoaderParams {
 public:
    LoaderParams(std::string t_key, float x, float y, int w, int h) :
        texture_key(t_key),
        frame_key(""),
        m_x(x),
        m_y(y),
        m_width(w),
        m_height(h),
        m_json(false) {}

    LoaderParams(std::string t_key, std::string f_key, float x, float y) :
        texture_key(t_key),
        frame_key(f_key),
        m_x(x),
        m_y(y),
        m_width(0),
        m_height(0),
        m_json(true) {}

    ~LoaderParams();

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    bool isJSON() const { return m_json; }

    std::string getTextureKey() const { return texture_key; }
    std::string getFrameKey() const { return frame_key; }

 private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    bool m_json;

    std::string texture_key;
    std::string frame_key;
};

#endif
