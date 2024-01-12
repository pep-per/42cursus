#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
  std::cout << "FragTrap without name is created by Default constructor"
            << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->hitPoints_ = 100;
  this->energyPoints_ = 100;
  this->attackDamage_ = 30;
  std::cout << "FragTrap " << this->name_ << " is created by Constructor"
            << std::endl;
}

FragTrap::FragTrap(const FragTrap& st) : ClapTrap(st) {
  *this = st;
  std::cout << "FragTrap " << this->name_ << " is created by Copy constructor"
            << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->name_ << " is destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& st) {
  std::cout << "Copy assignment operator copied FragTrap " << this->name_
            << " to FragTrap " << st.name_ << std::endl;
  this->name_ = st.name_;
  this->hitPoints_ = st.hitPoints_;
  this->energyPoints_ = st.energyPoints_;
  this->attackDamage_ = st.attackDamage_;
  return *this;
}

void FragTrap::attack(const std::string& target) {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "FragTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  this->energyPoints_--;
  std::cout << "FragTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void FragTrap::highFivesGuys() {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "FragTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  std::cout << "Yeah~ High fives guys!!" << std::endl;
}