#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
  std::cout << "ScavTrap without name is created by Default constructor"
            << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->hitPoints_ = 100;
  this->energyPoints_ = 50;
  this->attackDamage_ = 20;
  std::cout << "ScavTrap " << this->name_ << " is created by Constructor"
            << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& st) : ClapTrap(st) {
  *this = st;
  std::cout << "ScavTrap " << this->name_ << " is created by Copy constructor"
            << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->name_ << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& st) {
  std::cout << "Copy assignment operator copied ScavTrap " << this->name_
            << " to ScavTrap " << st.name_ << std::endl;
  this->name_ = st.name_;
  this->hitPoints_ = st.hitPoints_;
  this->energyPoints_ = st.energyPoints_;
  this->attackDamage_ = st.attackDamage_;
  return *this;
}

void ScavTrap::attack(const std::string& target) {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "ScavTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  this->energyPoints_--;
  std::cout << "ScavTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void ScavTrap::guardGate() {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "ScavTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode"
            << std::endl;
}