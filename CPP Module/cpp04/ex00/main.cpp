#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout
      << "================Create Instances - Animal, Cat, Dog================"
      << std::endl;
  const Animal* meta = new Animal();
  const Animal* i = new Cat();
  const Animal* j = new Dog();
  std::cout << std::endl;

  std::cout << "================getType()================" << std::endl;
  std::cout << meta->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << "================makeSound()================" << std::endl;
  meta->makeSound();
  i->makeSound();
  j->makeSound();
  std::cout << std::endl;

  std::cout
      << "================Destroy Instances - Animal, Cat, Dog================"
      << std::endl;
  delete meta;
  delete i;
  delete j;
  std::cout << std::endl;

  std::cout << "================Create Instances - WrongAnimal, "
               "WrongCat================"
            << std::endl;
  const WrongAnimal* meta2 = new WrongAnimal();
  const WrongAnimal* i2 = new WrongCat();
  std::cout << std::endl;

  std::cout << "================getType()================" << std::endl;
  std::cout << meta2->getType() << " " << std::endl;
  std::cout << i2->getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << "================makeSound()================" << std::endl;
  meta2->makeSound();
  i2->makeSound();
  std::cout << std::endl;

  std::cout << "================Destroy Instances - WrongAnimal, "
               "WrongCat================"
            << std::endl;
  delete meta2;
  delete i2;
  return 0;
}