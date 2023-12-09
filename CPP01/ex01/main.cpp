#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
  std::cout << "Enter Zombie name :";
  std::string name;
  std::getline(std::cin, name);
  std::cout << "Enter number of Zombie : ";
  int n;
  std::cin >> n;
  Zombie* horde = zombieHorde(n, name);
  for (int i = 0; i < n; i++) {
    std::cout << "no." << i + 1 << " ";
    horde->announce();
  }
  delete[] horde;
}