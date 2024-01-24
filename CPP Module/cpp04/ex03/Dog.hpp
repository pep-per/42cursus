#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 private:
  Brain* brain_;

 public:
  Dog();
  Dog(const Dog& obj);
  ~Dog();
  Dog& operator=(const Dog& obj);
  void makeSound() const;
  Brain* getBrain() const;
};

#endif