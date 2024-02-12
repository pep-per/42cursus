#include <iostream>
#include <sstream>

#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**) {
  // given test
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }
  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;

  // my test
  // const Array<std::string> strings(MAX_VAL);
  // std::string* mirror2 = new std::string[MAX_VAL];
  // for (int i = 0; i < MAX_VAL; i++) {
  //   std::ostringstream oss;
  //   oss << rand();
  //   const std::string value = oss.str();
  //   strings[i] = value;
  //   mirror2[i] = value;
  // }
  // for (int i = 0; i < MAX_VAL; i++) {
  //   if (mirror2[i] != strings[i]) {
  //     std::cerr << "didn't save the same value!!" << std::endl;
  //     return 1;
  //   }
  // }
  // try {
  //   strings[-2] = "Minus";
  // } catch (const std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }
  // try {
  //   strings[MAX_VAL] = "Out";
  // } catch (const std::exception& e) {
  //   std::cerr << e.what() << '\n';
  // }
  // {
  //   const Array<std::string> test = strings;
  //   for (int i = 0; i < MAX_VAL; i++) {
  //     std::ostringstream oss;
  //     oss << rand();
  //     strings[i] = oss.str();
  //     std::cout << "strings : " << strings[i] << "	"
  //               << "test : " << test[i] << std::endl;
  //   }
  // }
  // delete[] mirror2;
  return 0;
}