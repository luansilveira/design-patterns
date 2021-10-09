/*
 * Copyright (c) 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_PERSON_BUILDER_HPP_
#define DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_PERSON_BUILDER_HPP_

#include <string>

class PersonBuilder;
class PersonJobBuilder;
class PersonAddressBuilder;

class Person {
 public:
  std::string street_address_;
  std::string post_code_;
  std::string city_;
  std::string company_name_;
  std::string position_;
  int annual_income_{0};

  static PersonBuilder create();

  friend class PersonBuilder;
  friend class PersonJobBuilder;
  friend class PersonAddressBuilder;
};

class PersonBuilderBase {
 public:
  PersonBuilderBase(Person &person);

  PersonAddressBuilder lives();
  PersonJobBuilder works();

  operator Person();
 protected:
  Person &person_ref_;
};

class PersonBuilder : public PersonBuilderBase {
 public:
  PersonBuilder();

 private:
  Person person_;
};

class PersonAddressBuilder : public PersonBuilderBase {
  using Self = PersonAddressBuilder;
 public:
  PersonAddressBuilder(Person &p);

  Self &at(const std::string &street_address);

  Self &with_postcode(const std::string &post_code);

  Self &in(const std::string &city);
};

class PersonJobBuilder : public PersonBuilderBase {
  using Self = PersonJobBuilder;
 public:
  PersonJobBuilder(Person &p);

  Self &at(const std::string &company_name);

  Self &as_a(const std::string &position);

  Self &earning(int annual_income);
};


#endif  // DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_PERSON_BUILDER_HPP_
