#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default Constructor called" << std::endl;
  this->type_ = "Cat";
  this->brain_ = new Brain();
}

Cat::Cat(const Cat& obj) : Animal() {
  std::cout << "Cat Copy Constructor called" << std::endl;
  this->brain_ = new Brain();
  *this = obj;
}

Cat::~Cat() {
  std::cout << "Cat Destructor called" << std::endl;
  delete this->brain_;
}

Cat& Cat::operator=(const Cat& obj) {
  std::cout << "Cat Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
    delete this->brain_;
    this->brain_ = new Brain(*obj.brain_);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << this->type_ << " :	MEOW ~~~	" << std::endl;
}

Brain* Cat::getBrain() const { return this->brain_; }