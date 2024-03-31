#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& obj) : AMateria("ice") { this->source_ = obj.getSource(); }

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& obj) {
  if (this != &obj) {
  }
  return *this;
}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}