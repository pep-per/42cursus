#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
 protected:
  std::string type_;

 public:
  Animal();
  Animal(const Animal& obj);
  virtual ~Animal();
  Animal& operator=(const Animal& obj);
  virtual void makeSound() const;
  std::string getType() const;
};

#endif