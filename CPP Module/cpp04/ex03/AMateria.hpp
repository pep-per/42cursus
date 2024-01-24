#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria {
 protected:
  std::string type_;

 public:
  AMateria();
  AMateria(const AMateria& obj);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& obj);
  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif