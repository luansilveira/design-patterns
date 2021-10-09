/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include <cmath>

#include "drink.hpp"
#include "drink_factory.hpp"

class DrinkFactoryTests : public testing::Test {
 protected:
  DrinkFactory drink_factory_;
};

TEST_F(DrinkFactoryTests, MakeCoofee_ExpectNoThrow) {
  EXPECT_NO_THROW(drink_factory_.make_drink("coffee"));
}

TEST_F(DrinkFactoryTests, MakeCoffee_ExpectCoffee) {
  auto drink = drink_factory_.make_drink("coffee");
  EXPECT_TRUE(dynamic_cast<Coffee *>(drink.get()));
}

TEST_F(DrinkFactoryTests, MakeCoffee_ExpectNotTea) {
  auto drink = drink_factory_.make_drink("coffee");
  EXPECT_FALSE(dynamic_cast<Tea *>(drink.get()));
}

TEST_F(DrinkFactoryTests, MakeTea_ExpectNoThrow) {
  EXPECT_NO_THROW(drink_factory_.make_drink("tea"));
}

TEST_F(DrinkFactoryTests, MakeTea_ExpectTea) {
  auto drink = drink_factory_.make_drink("tea");
  EXPECT_TRUE(dynamic_cast<Tea *>(drink.get()));
}

TEST_F(DrinkFactoryTests, MakeTea_ExpectNotCoffee) {
  auto drink = drink_factory_.make_drink("tea");
  EXPECT_FALSE(dynamic_cast<Coffee *>(drink.get()));
}

TEST_F(DrinkFactoryTests, MakeNonExistingDrink_ExpectThrow) {
  EXPECT_THROW(drink_factory_.make_drink("juice"), std::out_of_range);
}

class DrinkMethodFactoryTests : public testing::Test {
 protected:
  DrinkMethodFactory drink_factory_;
};

TEST_F(DrinkMethodFactoryTests, MakeCoofee_ExpectNoThrow) {
  EXPECT_NO_THROW(drink_factory_.make_drink("coffee"));
}

TEST_F(DrinkMethodFactoryTests, MakeCoffee_ExpectCoffee) {
  auto drink = drink_factory_.make_drink("coffee");
  EXPECT_TRUE(dynamic_cast<Coffee *>(drink.get()));
}

TEST_F(DrinkMethodFactoryTests, MakeCoffee_ExpectNotTea) {
  auto drink = drink_factory_.make_drink("coffee");
  EXPECT_FALSE(dynamic_cast<Tea *>(drink.get()));
}

TEST_F(DrinkMethodFactoryTests, MakeTea_ExpectNoThrow) {
  EXPECT_NO_THROW(drink_factory_.make_drink("tea"));
}

TEST_F(DrinkMethodFactoryTests, MakeTea_ExpectTea) {
  auto drink = drink_factory_.make_drink("tea");
  EXPECT_TRUE(dynamic_cast<Tea *>(drink.get()));
}

TEST_F(DrinkMethodFactoryTests, MakeTea_ExpectNotCoffee) {
  auto drink = drink_factory_.make_drink("tea");
  EXPECT_FALSE(dynamic_cast<Coffee *>(drink.get()));
}

TEST_F(DrinkMethodFactoryTests, MakeNonExistingDrink_ExpectThrow) {
  EXPECT_THROW(drink_factory_.make_drink("juice"), std::out_of_range);
}
