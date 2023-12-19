#include "Contact.hpp"

Contact::Contact()
    : firstName_(""),
      lastName_(""),
      nickname_(""),
      phoneNumber_(""),
      darkestSecret_("") {}

Contact::~Contact() {}

std::string inputInfo() {
  std::string str;
  while (1) {
    if (std::cin.eof()) {
      clearerr(stdin);
      std::cin.clear();
      break;
    }
    std::getline(std::cin, str);
    str.erase(0, str.find_first_not_of(" \t\r\f\v"));
    if (!str.empty()) break;
  }
  return str;
}

void Contact::setFirstName() {
  std::cout << "first name : ";
  firstName_ = inputInfo();
}

void Contact::setLastName() {
  std::cout << "last name : ";
  lastName_ = inputInfo();
}

void Contact::setNickname() {
  std::cout << "nickname : ";
  nickname_ = inputInfo();
}

void Contact::setPhoneNumber() {
  std::cout << "phone number : ";
  phoneNumber_ = inputInfo();
}

void Contact::setDarkestSecret() {
  std::cout << "darkest secret : ";
  darkestSecret_ = inputInfo();
}

std::string Contact::getFirstName() { return firstName_; }

std::string Contact::getLastName() { return lastName_; }

std::string Contact::getNickname() { return nickname_; }

std::string Contact::getPhoneNumber() { return phoneNumber_; }

std::string Contact::getDarkestSecret() { return darkestSecret_; }