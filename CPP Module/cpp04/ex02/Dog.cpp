#include "Dog.hpp"

Dog::Dog() : AAnimal() {
  std::cout << "Dog Default Constructor called" << std::endl;
  this->type_ = "Dog";
  this->brain_ = new Brain();
}

Dog::Dog(const Dog& obj) : AAnimal() {
  std::cout << "Dog Copy Constructor called" << std::endl;
  this->brain_ = new Brain();
  *this = obj;
}

Dog::~Dog() {
  std::cout << "Dog Destructor called" << std::endl;
  delete this->brain_;
}

Dog& Dog::operator=(const Dog& obj) {
  std::cout << "Dog Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
    delete this->brain_;
    this->brain_ = new Brain(*obj.brain_);
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << this->type_ << " :	WOOF WOOF	" << std::endl;
}

Brain* Dog::getBrain() const { return this->brain_; }