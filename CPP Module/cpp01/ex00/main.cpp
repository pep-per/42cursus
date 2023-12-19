#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  Zombie* a = newZombie("Merry");
  a->announce();

  Zombie* b = new Zombie("Bunny");
  b->announce();

  Zombie c("Pan");
  c.announce();

  delete a;
  delete b;

  randomChump("Cherry");
  return 0;
}