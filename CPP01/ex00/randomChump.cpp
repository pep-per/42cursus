#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name) {
  Zombie* z = newZombie(name);
  z->announce();
  delete z;
}
