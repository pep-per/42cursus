#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class ICharacter;
class MateriaSource;

class AMateria {
 protected:
  std::string type_;
  MateriaSource* source_;

 public:
  AMateria();
  AMateria(const AMateria& obj);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& obj);

  AMateria(const std::string& type);
  const std::string& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

  MateriaSource* getSource();
  MateriaSource* getSource() const;
  void saveSource(MateriaSource* source);
};

#endif