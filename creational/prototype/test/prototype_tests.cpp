/*
 * Copyright (c) 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "prototype.hpp"

TEST(Prototype, CreateNewAddress_ExpectSuccess) {
  Address address{"Eindhoven", "18 Septemberplein 1", 123};
  EXPECT_EQ("Eindhoven", address.GetCity());
  EXPECT_EQ("18 Septemberplein 1", address.GetStreet());
  EXPECT_EQ(123, address.GetSuite());
}

TEST(Prototype, CreateNewAddressFromCopy_ExpectSuccess) {
  Address address1{"Eindhoven", "18 Septemberplein 1", 123};
  Address address2{address1};
  EXPECT_EQ("Eindhoven", address2.GetCity());
  EXPECT_EQ("18 Septemberplein 1", address2.GetStreet());
  EXPECT_EQ(123, address2.GetSuite());
}

TEST(Prototype, CreateNewContact_ExpectSuccess) {
  Contact contact{"Luan", std::make_shared<Address>(
                              "Eindhoven", "18 Septemberplein 1", 123)};
  EXPECT_EQ("Luan", contact.GetName());
  auto address = contact.GetAddress();
  EXPECT_EQ("Eindhoven", address->GetCity());
  EXPECT_EQ("18 Septemberplein 1", address->GetStreet());
  EXPECT_EQ(123, address->GetSuite());
}

TEST(Prototype, CreateNewContactFromCopy_ExpectSuccess) {
  Contact contact{"Luan", std::make_shared<Address>(
                              "Eindhoven", "18 Septemberplein 1", 123)};
  Contact contact2{contact};
  EXPECT_EQ("Luan", contact2.GetName());
  auto address = contact2.GetAddress();
  EXPECT_EQ("Eindhoven", address->GetCity());
  EXPECT_EQ("18 Septemberplein 1", address->GetStreet());
  EXPECT_EQ(123, address->GetSuite());
}

TEST(Prototype, CreateNewContactFromCopy_EnsureNameDeepCopied_ExpectSuccess) {
  Contact luan{"Luan", std::make_shared<Address>("Eindhoven",
                                                 "18 Septemberplein 1", 123)};
  Contact john{luan};
  john.SetName("John");
  EXPECT_EQ("Luan", luan.GetName());
  EXPECT_EQ("John", john.GetName());
}

TEST(Prototype,
     CreateNewContactFromCopy_EnsureAddressDeepCopied_ExpectSuccess) {
  Contact luan{"Luan", std::make_shared<Address>("Eindhoven",
                                                 "18 Septemberplein 1", 123)};
  Contact john{luan};
  auto luan_address = luan.GetAddress();
  auto john_address = john.GetAddress();
  john_address->SetSuite(456);
  EXPECT_EQ(123, luan_address->GetSuite());
  EXPECT_EQ(456, john_address->GetSuite());
}