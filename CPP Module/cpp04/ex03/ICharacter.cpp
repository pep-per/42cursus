#include "ICharacter.hpp"

ICharacter::ICharacter() {}
ICharacter::ICharacter(const ICharacter& obj) {}
ICharacter::~ICharacter() {}
ICharacter& ICharacter::operator=(const ICharacter& obj) {}
std::string const& ICharacter::getName() const {}
void ICharacter::equip(AMateria* m) {}
void ICharacter::unequip(int idx) {}
void ICharacter::use(int idx, ICharacter& target) {}