/**
 * Copyright 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_
#define DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_

#include <map>
#include <memory>
#include <string>

#include "drink.hpp"

class AbstractDrinkFactory {
 public:
  virtual ~AbstractDrinkFactory() = default;
  virtual std::unique_ptr<Drink> make() = 0;
};

class TeaFactory : public AbstractDrinkFactory {
 public:
  virtual ~TeaFactory() = default;
  std::unique_ptr<Drink> make() override;
};

class CoffeeFactory : public AbstractDrinkFactory {
 public:
  virtual ~CoffeeFactory() = default;
  std::unique_ptr<Drink> make() override;
};

class DrinkFactory {
 public:
  DrinkFactory();
  virtual ~DrinkFactory() = default;
  std::unique_ptr<Drink> make_drink(const std::string &name,
                                    int volume_ml = 200);

 private:
  std::map<std::string, std::unique_ptr<AbstractDrinkFactory>> factories;
};

#endif  // DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_FACTORY_HPP_
