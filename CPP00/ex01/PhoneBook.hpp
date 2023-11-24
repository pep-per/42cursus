#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
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