//
// Created by Luan Silveira on 05/10/2021.
//

#ifndef DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_
#define DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_

#include <memory>
#include <map>

#include "drink.hpp"

class AbstractDrinkFactory {
 public:
  virtual std::unique_ptr<Drink> make() = 0;
};

class TeaFactory : public AbstractDrinkFactory {
 public:
  std::unique_ptr<Drink> make() override;
};

class CoffeeFactory : public AbstractDrinkFactory {
 public:
  std::unique_ptr<Drink> make() override;
};

class DrinkFactory {
 public:
  DrinkFactory();
  std::unique_ptr<Drink> make_drink(const std::string &name, int volume);

 private:
  std::map <std::string, std::unique_ptr<AbstractDrinkFactory>> factories;
};

#endif  // DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_
