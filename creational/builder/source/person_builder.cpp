/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "person_builder.hpp"

PersonBuilder Person::create() {
  return PersonBuilder();
}
PersonBuilderBase::PersonBuilderBase(Person& person) : person_ref_{person} {}

PersonAddressBuilder PersonBuilderBase::lives() {
  return PersonAddressBuilder{person_ref_};
}

PersonJobBuilder PersonBuilderBase::works() {
  return PersonJobBuilder{person_ref_};
}

PersonBuilderBase::operator Person() {
  return person_ref_;
}

PersonBuilder::PersonBuilder() : PersonBuilderBase(person_) {}

PersonAddressBuilder::PersonAddressBuilder(Person& p) : PersonBuilderBase(p) {}

PersonAddressBuilder::Self& PersonAddressBuilder::at(
    const std::string& street_address) {
  person_ref_.street_address_ = street_address;
  return *this;
}

PersonAddressBuilder::Self& PersonAddressBuilder::with_postcode(
    const std::string& post_code) {
  person_ref_.post_code_ = post_code;
  return *this;
}

PersonAddressBuilder::Self& PersonAddressBuilder::in(const std::string& city) {
  person_ref_.city_ = city;
  return *this;
}

PersonJobBuilder::PersonJobBuilder(Person& p) : PersonBuilderBase(p) {}

PersonJobBuilder::Self& PersonJobBuilder::at(const std::string& company_name) {
  person_ref_.company_name_ = company_name;
  return *this;
}

PersonJobBuilder::Self& PersonJobBuilder::as_a(const std::string& position) {
  person_ref_.position_ = position;
  return *this;
}

PersonJobBuilder::Self& PersonJobBuilder::earning(int annual_income) {
  person_ref_.annual_income_ = annual_income;
  return *this;
}
