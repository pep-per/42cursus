#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "================Create Instances Array - Half Cats, Half "
               "Dogs=================";
  const AAnimal *animals[10];
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      animals[i] = new Cat();
    else
      animals[i] = new Dog();
  }
  std::cout << std::endl;

  std::cout
      << "================Get Type & Destroy Instances Array================="
      << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << std::endl
              << "No." << i << " Animal type is " << animals[i]->getType()
              << std::endl;
    animals[i]->makeSound();
    delete animals[i];
  }
  std::cout << std::endl;

  std::cout << "================Check Deep Copy=================" << std::endl;
  Cat cat1;
  cat1.getBrain()->setIdeas("I want some milk", 0);
  std::cout << "cat1 is thinking	->	"
            << cat1.getBrain()->getIdeas(0) << std::endl;
  Cat cat2(cat1);
  std::cout << "cat2 is thinking	->	"
            << cat2.getBrain()->getIdeas(0) << std::endl;
  Cat cat3;
  cat3 = cat1;
  cat1.getBrain()->setIdeas("Don't bother me", 0);
  std::cout << "cat3 is thinking	->	"
            << cat3.getBrain()->getIdeas(0) << std::endl;
  std::cout << "cat1 is thinking	->	"
            << cat1.getBrain()->getIdeas(0) << std::endl;
  return 0;
}