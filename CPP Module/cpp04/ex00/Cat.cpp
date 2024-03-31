#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default Constructor called" << std::endl;
  this->type_ = "Cat";
}

Cat::Cat(const Cat& obj) : Animal() {
  std::cout << "Cat Copy Constructor called" << std::endl;
  *this = obj;
}

Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; }

Cat& Cat::operator=(const Cat& obj) {
  std::cout << "Cat Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << this->type_ << " :	MEOW ~~~	" << std::endl;
}
