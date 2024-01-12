#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  this->type_ = "WrongCat";
  std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal() {
  *this = obj;
  std::cout << "WrongCat Copy Constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << this->type_ << " :	MEOW ~~~	" << std::endl;
}