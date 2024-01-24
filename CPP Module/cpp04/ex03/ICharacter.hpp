#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"

class ICharacter {
 private:
  std::string name_;
  AMateria* inventory_[4];
  int inventory_count_;

 public:
  ICharacter();
  ICharacter(const ICharacter& obj);
  virtual ~ICharacter();
  virtual ICharacter& operator=(const ICharacter& obj);
  virtual std::string const& getName() const = 0;
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};

#endif