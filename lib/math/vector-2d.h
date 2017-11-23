/**
 * Atena Game Engine
 * vector-2d.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef __Vector2D__
#define __Vector2D__

#include <math.h>

class Vector2D {
public:
  Vector2D() {
    m_x = 0;
    m_y = 0;
  }

  Vector2D(float x, float y) :
  m_x(x),
  m_y(y) {}

  float getX() { return m_x; }
  float getY() { return m_y; }

  void setX(float x) { m_x = x; }
  void setY(float y) { m_y = y; }

  float length() { return sqrt(m_x * m_x + m_y * m_y ); }

  void normalize() {
    float l = length();
    if (l > 0) {
      (*this) *= 1 / l;
    }
  }

  /*
   * Addition
   */
  Vector2D operator+(const Vector2D& v2) const {
    return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
  }

  friend Vector2D& operator+=(Vector2D &v1, const Vector2D &v2) {
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;

    return v1;
  }

  /*
   * Subtraction
   */
  Vector2D operator-(const Vector2D &v2) const {
    return Vector2D(m_x - v2.m_x, m_y + v2.m_y);
  }

  friend Vector2D& operator-=(Vector2D &v1, const Vector2D &v2) {
    v1.m_x -= v2.m_x;
    v1.m_y -= v2.m_y;

    return v1;
  }

  /*
   * Scalar multiplication
   */
  Vector2D operator*(float scalar) {
    return Vector2D(m_x * scalar, m_y * scalar);
  }

  Vector2D operator*=(float scalar) {
    m_x *= scalar;
    m_y *= scalar;

    return *this;
  }

  /*
   * Scalar division
   */
  Vector2D operator/(float scalar) {
    return Vector2D(m_x / scalar, m_y / scalar);
  }

  Vector2D& operator/=(float scalar) {
    m_x /= scalar;
    m_y /= scalar;

    return *this;
  }

private:
  float m_x;
  float m_y;
};

#endif
