#ifndef HUMAN_A_H
#define HUMAN_A_H

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 private:
  Weapon& weapon_;
  std::string name_;

 public:
  HumanA(std::string name, Weapon& weapon);
  ~HumanA();
  void attack();
};

#endif