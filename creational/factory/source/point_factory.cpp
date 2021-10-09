/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "point_factory.hpp"

#include <cmath>

Point::Point(float x, float y)
    : x{x}, y{y} {}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  os << "x: " << point.x << " y: " << point.y;
  return os;
}

Point PointFactory::CreateCartesian(float x, float y) { return {x, y}; }

Point PointFactory::CreatePolar(float r, float theta) {
  return {r * std::cos(theta), r * std::sin(theta)};
}
