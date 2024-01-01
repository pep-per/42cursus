#include "PhoneBook.hpp"

int main() {
  PhoneBook phonebook;
  std::string cmd;
  while (1) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Command [ADD] [SEARCH] [EXIT] : ";
    std::getline(std::cin, cmd);
    if (cmd == "ADD") {
      phonebook.addContact();
    } else if (cmd == "SEARCH") {
      phonebook.searchContact();
    } else if (cmd == "EXIT" || std::cin.eof())
      break;
  }
  return 0;
}