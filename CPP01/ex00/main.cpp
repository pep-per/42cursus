#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

void leak(void) { system("leaks ex00"); }

char* _test() {
  char* temp = (char*)malloc(100);
  return (temp);
}

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
  // char* str;
  // str = (char*)malloc(100);
  // str = _test();

  // free(str);

  // Zombie* bob = new Zombie("Bob");
  // // bob->announce();

  // Zombie* steve = newZombie("Steve");
  // steve->announce();

  // randomChump("Anne");

  // // delete bob;
  // delete steve;
  return 0;
}