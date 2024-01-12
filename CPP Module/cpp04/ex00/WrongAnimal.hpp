#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& obj);
  ~WrongAnimal();
  WrongAnimal& operator=(const WrongAnimal& obj);
  void makeSound() const;
  std::string getType() const;
};

#endif