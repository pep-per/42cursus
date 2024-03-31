#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog Default Constructor called" << std::endl;
  this->type_ = "Dog";
}

Dog::Dog(const Dog& obj) : Animal() {
  std::cout << "Dog Copy Constructor called" << std::endl;
  *this = obj;
}

Dog::~Dog() { std::cout << "Dog Destructor called" << std::endl; }

Dog& Dog::operator=(const Dog& obj) {
  std::cout << "Dog Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << this->type_ << " :	WOOF WOOF	" << std::endl;
}