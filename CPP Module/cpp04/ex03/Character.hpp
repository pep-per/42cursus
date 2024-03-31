#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define INV_SIZE 4
#define INV_EMPTY -1

class Character : public ICharacter {
 private:
  std::string name_;
  AMateria* inventory_[INV_SIZE];
  int inventoryCount_;

 public:
  Character();
  Character(const std::string& name);
  Character(const Character& obj);
  virtual ~Character();
  Character& operator=(const Character& obj);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
  int findEmptySlot();
};

#endif