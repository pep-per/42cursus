#include "AMateria.hpp"

AMateria::AMateria() : type_("AMateria"), source_(NULL) {}

AMateria::AMateria(const std::string& type) : type_(type), source_(NULL) {}

AMateria::AMateria(const AMateria& obj) { *this = obj; }

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& obj) {
  if (this != &obj) {
  }
  return *this;
}

const std::string& AMateria::getType() const { return this->type_; }

MateriaSource* AMateria::getSource() { return this->source_; }

MateriaSource* AMateria::getSource() const { return this->source_; }

void AMateria::saveSource(MateriaSource* source) { this->source_ = source; }

void AMateria::use(ICharacter& target) {
  std::cout << "Does nothing to " << target.getName() << std::endl;
}