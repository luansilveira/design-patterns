/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "person_builder.hpp"

TEST(PersonBuilderTestSuite, Create) {
  Person p = Person::create()
                 .works()
                 .at("Philips")
                 .as_a("Software Engineer")
                 .earning(100000)
                 .lives()
                 .at("18 Septemberplein 1 ")
                 .with_postcode("5611AL")
                 .at("Eindhoven");
  ASSERT_TRUE(true);
}
