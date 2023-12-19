#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie {
 private:
  std::string name_;

 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void announce();
};

#endif