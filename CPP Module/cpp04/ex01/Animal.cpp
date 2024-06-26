#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
  std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) {
  std::cout << "Animal Copy Constructor called" << std::endl;
  *this = obj;
}

Animal::~Animal() { std::cout << "Animal Destructor called" << std::endl; }

Animal& Animal::operator=(const Animal& obj) {
  std::cout << "Animal Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  return *this;
}

void Animal::makeSound() const {
  std::cout << this->type_ << " :	. . .	" << std::endl;
}

std::string Animal::getType() const { return this->type_; }