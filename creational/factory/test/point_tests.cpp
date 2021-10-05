/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include <cmath>

#include "point_factory.hpp"

TEST(PointTestSuite, Constructor) {
  Point p{1, 2};
  EXPECT_EQ(p.x, 1);
  EXPECT_EQ(p.y, 2);
}

TEST(PointTestSuite, CreateCartesian) {
  Point p = PointFactory::CreateCartesian(1, 2);
  EXPECT_EQ(p.x, 1);
  EXPECT_EQ(p.y, 2);
}

TEST(PointTestSuite, CreatePolar) {
  Point p = PointFactory::CreatePolar(10, M_PI/3);
  EXPECT_NEAR(p.x, 5, 1e-6);
  EXPECT_NEAR(p.y, 8.660254, 1e-6);
}
