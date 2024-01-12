#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
 protected:
  std::string type_;

 public:
  AAnimal();
  AAnimal(const AAnimal& obj);
  virtual ~AAnimal();
  AAnimal& operator=(const AAnimal& obj);
  virtual void makeSound() const = 0;
  std::string getType() const;
};

#endif