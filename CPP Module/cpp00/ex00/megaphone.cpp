#include <iostream>

int main(int ac, char **av) {
  if (ac == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  std::string str;
  for (int i = 1; i < ac; i++) {
    str = av[i];
    for (size_t j = 0; j < str.size(); j++) {
      str[j] = toupper(str[j]);
    }
    std::cout << str;
  }
  std::cout << std::endl;
  return 0;
}