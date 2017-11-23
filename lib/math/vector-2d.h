/**
 * Atena Game Engine
 * vector-2d.h
 *
 * Copyright 2014-present [Ricard Sole <@rcsole, ricardsolecasas@gmail.com>]
 */

#ifndef LIB_MATH_VECTOR_2D_H_
#define LIB_MATH_VECTOR_2D_H_

#include <math.h>

class Vector2D {
 public:
  Vector2D() {
    x_position = 0;
    y_position = 0;
  }

  Vector2D(float x, float y) : x_position(x), y_position(y) {}

  float get_x_position() { return x_position; }
  float get_y_position() { return x_position; }

  void set_x_position(float x) { x_position = x; }
  void set_y_position(float y) { y_position = y; }

  float length() {
    return sqrt(x_position * x_position + y_position * y_position);
  }

  void normalize() {
    float l = length();
    if (l > 0) {
      (*this) *= 1 / l;
    }
  }

  /*
   * Addition
   */
  Vector2D operator+(const Vector2D &v2) const {
    return Vector2D(x_position + v2.x_position, y_position + v2.y_position);
  }

  friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2) {
    v1.x_position += v2.x_position;
    v1.y_position += v2.y_position;

    return v1;
  }

  /*
   * Subtraction
   */
  Vector2D operator-(const Vector2D &v2) const {
    return Vector2D(x_position - v2.x_position, y_position + v2.y_position);
  }

  friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2) {
    v1.x_position -= v2.x_position;
    v1.y_position -= v2.y_position;

    return v1;
  }

  /*
   * Scalar multiplication
   */
  Vector2D operator*(float scalar) {
    return Vector2D(x_position * scalar, y_position * scalar);
  }

  Vector2D operator*=(float scalar) {
    x_position *= scalar;
    y_position *= scalar;

    return *this;
  }

  /*
   * Scalar division
   */
  Vector2D operator/(float scalar) {
    return Vector2D(x_position / scalar, y_position / scalar);
  }

  Vector2D &operator/=(float scalar) {
    x_position /= scalar;
    y_position /= scalar;

    return *this;
  }

 private:
  float x_position;
  float y_position;
};

#endif  // LIB_MATH_VECTOR_2D_H_
