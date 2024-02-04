#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
  if (rand() % 3 == 0)
    return (new A());
  else if (rand() % 3 == 1)
    return (new B());
  else
    return (new C());
}

void identify(Base *p) {
  std::cout << "identify by pointer" << std::endl;
  if (dynamic_cast<A *>(p)) {
    std::cout << "A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C" << std::endl;
  } else
    std::cout << "Error: unknown type" << std::endl;
}

void identify(Base &p) {
  std::cout << "identify by reference" << std::endl;
  try {
    A a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    B b = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    C c = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {
    throw e;
  }
}

int main() {
  srand((unsigned int)time(NULL));
  try {
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    Base *base = new Base();
    identify(base);
    identify(*base);
    delete base;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}