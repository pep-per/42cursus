#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name_(""), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap without name is created by Default constructor"
            << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap " << this->name_ << " is created by Constructor"
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct) {
  *this = ct;
  std::cout << "ClapTrap " << this->name_ << " is created by Copy constructor"
            << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << this->name_ << " is destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ct) {
  std::cout << "Copy assignment operator copied ClapTrap " << this->name_
            << " to ClapTrap " << ct.name_ << std::endl;
  this->name_ = ct.name_;
  this->hitPoints_ = ct.hitPoints_;
  this->energyPoints_ = ct.energyPoints_;
  this->attackDamage_ = ct.attackDamage_;
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "ClapTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  this->energyPoints_--;
  std::cout << "ClapTrap " << this->name_ << " attacks " << target
            << ", causing " << this->attackDamage_ << " points of damage!"
            << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "ClapTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  if (this->hitPoints_ >= amount)
    this->hitPoints_ -= amount;
  else
    this->hitPoints_ = 0;
  std::cout << "ClapTrap " << this->name_ << " takes " << amount
            << " point of damage" << std::endl;
  if (this->hitPoints_ == 0)
    std::cout << "ClapTrap " << this->name_ << " is broken" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->hitPoints_ == 0 || this->energyPoints_ == 0) {
    std::cout << "ClapTrap " << this->name_ << " is already broken"
              << std::endl;
    return;
  }
  this->hitPoints_ += amount;
  this->energyPoints_--;
  std::cout << "ClapTrap " << this->name_ << " is repaired by " << amount
            << " points" << std::endl;
}