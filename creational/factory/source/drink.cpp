/**
 * Copyright 2021 Luan Silveira
 */

#include "drink.hpp"

#include <iostream>

void Tea::prepare(int volume) {
  std::cout << "Take tea bag, boil water, pour " << volume
            << "ml, add some lemon\n";
}

void Coffee::prepare(int volume) {
  std::cout << "Grind some beans, boil water, pur " << volume
            << "ml, add cream, enjoy!\n";
}
