/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "drink_factory.hpp"

std::unique_ptr<Drink> TeaFactory::make() { return std::make_unique<Tea>(); }

std::unique_ptr<Drink> CoffeeFactory::make() {
  return std::make_unique<Coffee>();
}

DrinkFactory::DrinkFactory() {
  factories.emplace("coffee", std::make_unique<CoffeeFactory>());
  factories.emplace("tea", std::make_unique<TeaFactory>());
}

std::unique_ptr<Drink> DrinkFactory::make_drink(const std::string &name,
                                                int volume_ml) {
  auto drink = factories.at(name)->make();
  drink->prepare(volume_ml);
  return drink;
}

DrinkMethodFactory::DrinkMethodFactory() {
  factories["coffee"] = []() {
    auto drink = std::make_unique<Coffee>();
    drink->prepare(50);
    return drink;
  };
  factories["tea"] = []() {
    auto drink = std::make_unique<Tea>();
    drink->prepare(200);
    return drink;
  };
}

std::unique_ptr<Drink> DrinkMethodFactory::make_drink(const std::string &name) {
  return factories.at(name)();
}
