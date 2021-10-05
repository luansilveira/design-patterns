//
// Created by Luan Silveira on 05/10/2021.
//

#ifndef DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_HPP_
#define DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_HPP_

class Drink {
 public:
  virtual ~Drink() = default;
  virtual void prepare(int volume) = 0;
};

class Tea: public Drink {
  void prepare(int volume) override;
};

class Coffee : public Drink {
 public:
  void prepare(int volume) override;
};

#endif  // DESIGN_PATTERNS_CREATIONAL_FACTORY_SOURCE_DRINK_HPP_