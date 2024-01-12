#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("AAnimal") {
  std::cout << "AAnimal Default Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) {
  *this = obj;
  std::cout << "AAnimal Copy Constructor called" << std::endl;
}

AAnimal::~AAnimal() { std::cout << "AAnimal Destructor called" << std::endl; }

AAnimal& AAnimal::operator=(const AAnimal& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
  return *this;
}

void AAnimal::makeSound() const {
  std::cout << this->type_ << " :	. . .	" << std::endl;
}

std::string AAnimal::getType() const { return this->type_; }