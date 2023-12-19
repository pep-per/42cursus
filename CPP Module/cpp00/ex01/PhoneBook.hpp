#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>

#include "Contact.hpp"

class PhoneBook {
 private:
  Contact list_[8];
  int idx_;

 public:
  PhoneBook();
  ~PhoneBook();
  void addContact();
  void searchContact();
  void showInCol(std::string str);
};

#endif