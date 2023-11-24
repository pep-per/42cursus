#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName_;
		std::string lastName_;
		std::string nickname_;
		std::string phoneNumber_;
		std::string darkestSecret_;
	public:
		Contact();
		~Contact();
		std::string setInfo(std::string field);
		void setFirstName();
		void setLastName();
		void setNickname();
		void setPhoneNumber();
		void setDarkestSecret();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif