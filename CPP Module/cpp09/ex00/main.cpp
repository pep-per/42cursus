#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cerr << "Usage: ./btc input.txt" << std::endl;
    return 1;
  }
  try {
    BitcoinExchange be(av[1]);
    be.parseDataBase();
    be.parseInputFile();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}