#include "Dog.hpp"

Dog::Dog() : Animal() {
  this->type_ = "Dog";
  std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) : Animal() {
  *this = obj;
  std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog Destructor called" << std::endl; }

Dog& Dog::operator=(const Dog& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "Dog Copy Assignment Operator called" << std::endl;
  return *this;
}

void Dog::makeSound() const {
  std::cout << this->type_ << " :	WOOF WOOF	" << std::endl;
}