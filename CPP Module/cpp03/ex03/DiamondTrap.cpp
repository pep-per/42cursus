#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  this->hitPoints_ = FragTrap::hitPoints_;
  this->energyPoints_ = ScavTrap::energyPoints_;
  this->attackDamage_ = FragTrap::attackDamage_;
  std::cout << "DiamondTrap without name is created by Default constructor"
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(), ScavTrap(), FragTrap() {
  this->hitPoints_ = FragTrap::hitPoints_;
  this->energyPoints_ = ScavTrap::energyPoints_;
  this->attackDamage_ = FragTrap::attackDamage_;
  this->name_ = name;
  ClapTrap::name_ = name + "_clap_name";
  std::cout << "DiamondTrap " << this->name_ << " is created by Constructor"
            << std::endl;
  ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& st)
    : ClapTrap(), ScavTrap(), FragTrap() {
  *this = st;
  std::cout << "DiamondTrap " << this->name_
            << " is created by Copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << this->name_ << " is destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& st) {
  std::cout << "Copy assignment operator copied DiamondTrap " << this->name_
            << " to DiamondTrap " << st.name_ << std::endl;
  this->hitPoints_ = st.hitPoints_;
  this->energyPoints_ = st.energyPoints_;
  this->attackDamage_ = st.attackDamage_;
  this->name_ = st.name_;
  ClapTrap::name_ = st.ClapTrap::name_;
  return *this;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << ClapTrap::name_ << " as ClapTrap "
            << "and " << DiamondTrap::name_ << " as DiamondTrap " << std::endl;
  std::cout << "My hit points are " << this->hitPoints_ << std::endl;
  std::cout << "My energy points are " << this->energyPoints_ << std::endl;
  std::cout << "My attack damage is " << this->attackDamage_ << std::endl;
}