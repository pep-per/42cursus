#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat Default Constructor called" << std::endl;
  this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal() {
  std::cout << "WrongCat Copy Constructor called" << std::endl;
  *this = obj;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
  std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << this->type_ << " :	MEOW ~~~	" << std::endl;
}