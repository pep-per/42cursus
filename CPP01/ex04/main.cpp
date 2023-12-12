#include "Replacer.hpp"

int main(int ac, char **av) {
  if (ac != 4) return 1;
  Replacer replacer(av[1], av[2], av[3]);
  replacer.newFile();
  return 0;
}