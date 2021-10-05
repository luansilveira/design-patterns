/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include <cmath>

#include "drink_factory.hpp"

TEST(DrinkFactoryTestSuite, MakeCoffe) {
  ASSERT_NO_THROW(DrinkFactory::make_drink("coffee"));
}

TEST(DrinkFactoryTestSuite, MakeTea) {
  ASSERT_NO_THROW(DrinkFactory::make_drink("tea"));
}
