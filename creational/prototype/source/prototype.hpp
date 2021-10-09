/*
 * Copyright (c) 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_BEHAVIORAL_PROTOTYPE_SOURCE_RECORD_KEEPING_HPP_
#define DESIGN_PATTERNS_BEHAVIORAL_PROTOTYPE_SOURCE_RECORD_KEEPING_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Address {
 public:
  Address(const std::string& city, const std::string& street, int suite);
  explicit Address(const Address& other) = default;
  const std::string& GetCity() const;
  const std::string& GetStreet() const;
  int GetSuite() const;
  void SetSuite(int suite);

 private:
  std::string city_;
  std::string street_;
  int suite_;
};

class Contact {
 public:
  Contact(const std::string& name, const std::shared_ptr<Address>& address);
  explicit Contact(const Contact& other);
  const std::string GetName() const;
  const std::shared_ptr<Address> GetAddress() const;
  void SetName(const std::string& name);

 private:
  std::string name_;
  std::shared_ptr<Address> address_;
};

#endif  // DESIGN_PATTERNS_BEHAVIORAL_PROTOTYPE_SOURCE_RECORD_KEEPING_HPP_
