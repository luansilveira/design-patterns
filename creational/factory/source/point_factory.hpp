/*
 * Copyright (c) 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_BEHAVIORAL_FACTORY_SOURCE_POINT_HPP_
#define DESIGN_PATTERNS_BEHAVIORAL_FACTORY_SOURCE_POINT_HPP_

#include <iostream>
#include <string>
#include <vector>

class Point {
 public:
  Point(float x, float y);
  friend std::ostream& operator<<(std::ostream& os, const Point& point);
  float x;
  float y;
};

class PointFactory {
 public:
  PointFactory() = delete;
  static Point CreateCartesian(float x, float y);
  static Point CreatePolar(float r, float theta);
};


#endif  // DESIGN_PATTERNS_BEHAVIORAL_FACTORY_SOURCE_POINT_HPP_
