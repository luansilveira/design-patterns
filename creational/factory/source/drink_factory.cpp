//
// Created by Luan Silveira on 05/10/2021.
//

#include "drink_factory.hpp"

std::unique_ptr<Drink> TeaFactory::make() {
  return std::make_unique<Tea>();
}

std::unique_ptr<Drink> CoffeeFactory::make() {
  return std::make_unique<Coffee>();
}

DrinkFactory::DrinkFactory() {
  factories["coffee"] = std::make_unique<CoffeeFactory>();
  factories["tea"] = std::make_unique<TeaFactory>();
}

std::unique_ptr<Drink> DrinkFactory::make_drink(const std::string &name, int volume = 200) {
  auto drink = factories.at(name)->make();
  drink.prepare(volume);
  return drink;
}
