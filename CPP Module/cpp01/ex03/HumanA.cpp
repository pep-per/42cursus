#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
  std::cout << this->name_ << " attacks with their " << this->weapon_.getType()
            << std::endl;
}
