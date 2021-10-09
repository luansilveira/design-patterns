/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "prototype.hpp"

Address::Address(const std::string& city, const std::string& street, int suite)
    : city_{city}, street_{street}, suite_{suite} {}

const std::string& Address::GetCity() const { return city_; }

const std::string& Address::GetStreet() const { return street_; }

int Address::GetSuite() const { return suite_; }

void Address::SetSuite(int suite) { suite_ = suite; }

Contact::Contact(const std::string& name,
                 const std::shared_ptr<Address>& address)
    : name_{name}, address_{address} {}

Contact::Contact(const Contact& other)
    : name_{other.name_},
      address_{std::make_shared<Address>(*other.address_)} {}

const std::string Contact::GetName() const { return name_; }

const std::shared_ptr<Address> Contact::GetAddress() const { return address_; }

void Contact::SetName(const std::string& name) { name_ = name; }
