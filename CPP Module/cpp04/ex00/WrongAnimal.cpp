#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
  std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
  *this = obj;
  std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << this->type_ << " :	. . .	" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type_; }