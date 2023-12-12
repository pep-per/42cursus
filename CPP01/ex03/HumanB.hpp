#ifndef HUMAN_B_H
#define HUMAN_B_H

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 private:
  Weapon *weapon_;
  std::string name_;

 public:
  HumanB(std::string name);
  ~HumanB();
  void attack();
  void setWeapon(Weapon &weapon);
};

#endif