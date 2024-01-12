#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
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