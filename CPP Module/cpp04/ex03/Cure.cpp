#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& obj) : AMateria("cure") {
  this->source_ = obj.getSource();
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& obj) {
  if (this != &obj) {
  }
  return *this;
}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}