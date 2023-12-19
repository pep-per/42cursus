#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name) {}

HumanB::~HumanB() {}

void HumanB::attack() {
  std::cout << this->name_ << " attacks with their " << weapon_->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon_ = &weapon; }
