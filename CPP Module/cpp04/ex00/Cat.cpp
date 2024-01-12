#include "Cat.hpp"

Cat::Cat() : Animal() {
  this->type_ = "Cat";
  std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) : Animal() {
  *this = obj;
  std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat Destructor called" << std::endl; }

Cat& Cat::operator=(const Cat& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "Cat Copy Assignment Operator called" << std::endl;
  return *this;
}

void Cat::makeSound() const {
  std::cout << this->type_ << " :	MEOW ~~~	" << std::endl;
}
