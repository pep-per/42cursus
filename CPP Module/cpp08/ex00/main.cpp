#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::cout << "=========== List ===========" << std::endl;
  try {
    std::list<int> v;
    v.push_back(17);
    v.push_back(42);
    v.push_back(9);
    v.push_back(3);
    v.push_back(6);
    v.push_back(77);
    v.push_back(8);
    v.push_back(-9);
    v.push_back(0);
    v.push_back(-23);
    std::list<int>::iterator it = easyfind(v, -9);
    std::cout << "Found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not Found" << std::endl;
  }

  std::cout << "========== Vector ==========" << std::endl;
  try {
    std::vector<int> v;
    v.push_back(17);
    v.push_back(42);
    v.push_back(9);
    v.push_back(3);
    v.push_back(6);
    v.push_back(77);
    v.push_back(8);
    v.push_back(-9);
    v.push_back(0);
    v.push_back(-23);
    std::vector<int>::iterator it = easyfind(v, 77);
    std::cout << "Found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cout << "Not Found" << std::endl;
  }
  return 0;
}