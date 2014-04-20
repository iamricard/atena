/**
 * Atena Game Engine
 * LoaderParams.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricard.solecasas@gmail.com>]
 */

class LoaderParams {
 public:
    // virtual void load(std::string t_key, std::string f_key,
    //                 int frames,
    //                 int dstX, int dstY)=0;
    // virtual void load(std::string t_key, int dstX, int dstY, int w, int h)=0;
    LoaderParams(std::string t_key, int x, int y, int w, int h) :
        texture_key(t_key),
        frame_key(""),
        m_x(x),
        m_y(y),
        m_width(w),
        m_height(h) {}

    LoaderParams(std::string t_key, std::string f_key, int x, int y) :
        texture_key(t_key),
        frame_key(f_key),
        m_x(x),
        m_y(y),
        m_width(0),
        m_height(0) {}

    ~LoaderParams();

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    std::string getTextureKey() const { return texture_key; }
    std::string getFrameKey() const { return frame_key; }

 private:
    int m_x;
    int m_y;

    int m_width;
    int m_height;

    std::string texture_key;
    std::string frame_key;
};