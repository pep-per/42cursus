#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : idx_(0) {
  for (int i = 0; i < 8; i++) {
    list_[i] = Contact();
  }
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
  Contact contact;
  contact.setFirstName();
  if (contact.getFirstName().empty()) return;
  contact.setLastName();
  if (contact.getLastName().empty()) return;
  contact.setNickname();
  if (contact.getNickname().empty()) return;
  contact.setPhoneNumber();
  if (contact.getPhoneNumber().empty()) return;
  contact.setDarkestSecret();
  if (contact.getDarkestSecret().empty()) return;
  list_[idx_] = contact;
  idx_ = (idx_ + 1) % 8;
  std::cout << "Saved a Contact successfully!" << std::endl;
};

void PhoneBook::showInCol(std::string str) {
  if (str.size() > 10) {
    str = str.substr(0, 10);
    str[9] = '.';
  }
  std::cout << std::setw(10) << str << "|";
}

void PhoneBook::searchContact() {
  std::cout << "|     index|first name| last name|  nickname|" << std::endl;
  int i = 0;
  while (i < 8 && !list_[i].getFirstName().empty()) {
    std::cout << "|         " << i << "|";
    showInCol(list_[i].getFirstName());
    showInCol(list_[i].getLastName());
    showInCol(list_[i].getNickname());
    std::cout << std::endl;
    i++;
  }
  while (1) {
    std::cout << "Contact to display [index] : ";
    int val;
    std::cin >> val;
    if (std::cin.fail()) {
      if (std::cin.eof()) {
        clearerr(stdin);
        std::cin.clear();
        std::cout << std::endl;
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "The input is invalid. Please enter a valid index."
                << std::endl;
      continue;
    }
    if ((val >= 0 && val < 8) && !list_[val].getFirstName().empty()) {
      std::cout << "first name    | " << list_[val].getFirstName() << std::endl;
      std::cout << "last name     | " << list_[val].getLastName() << std::endl;
      std::cout << "nickname      | " << list_[val].getNickname() << std::endl;
      std::cout << "phone number  | " << list_[val].getPhoneNumber()
                << std::endl;
      std::cout << "darket secret | " << list_[val].getDarkestSecret()
                << std::endl;
      std::cin.ignore();
      break;
    } else
      std::cout << "The input is invalid. Please enter a valid index."
                << std::endl;
  }
}