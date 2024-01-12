#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain_;

 public:
  Cat();
  Cat(const Cat& obj);
  ~Cat();
  Cat& operator=(const Cat& obj);
  void makeSound() const;
  Brain* getBrain() const;
};

#endif