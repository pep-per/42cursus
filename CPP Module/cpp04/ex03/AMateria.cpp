#include "AMateria.hpp"

AMateria::AMateria() : type_("AMateria") {
  std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& obj) {
  *this = obj;
  std::cout << "AMateria Copy Constructor called" << std::endl;
}

AMateria::~AMateria() {
  std::cout << "AMateria Destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj) {
  if (this != &obj) {
    this->type_ = obj.getType();
  }
  std::cout << "AMateria Copy Assignment Operator called" << std::endl;
  return *this;
}

std::string AMateria::getType() const { return this->type_; }