/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:19:47 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/11/24 21:22:10 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName_(""), lastName_(""), nickname_(""), 
						phoneNumber_(""), darkestSecret_("") {}

Contact::~Contact() {}

std::string Contact::setInfo(std::string field) {
	std::string str;
	while (1) {
		if (std::cin.eof())
			break;
		std::cout << field;
		std::getline(std::cin, str);
		str.erase(0, str.find_first_not_of(" \t\r\f\v"));
		if (!str.empty())
			break;
	}
	return str;
}

void Contact::setFirstName() {
	firstName_ = setInfo("first name : ");
}

void Contact::setLastName() {
	lastName_ = setInfo("last name : ");
}

void Contact::setNickname() {
	nickname_ = setInfo("nickname : ");
}

void Contact::setPhoneNumber() {
	phoneNumber_ = setInfo("phone number : ");
}

void Contact::setDarkestSecret() {
	darkestSecret_ = setInfo("darkest secret : ");
}

std::string Contact::getFirstName() {
	return firstName_;
}

std::string Contact::getLastName() {
	return lastName_;
}

std::string Contact::getNickname() {
	return nickname_;
}

std::string Contact::getPhoneNumber() {
	return phoneNumber_;
}

std::string Contact::getDarkestSecret() {
	return darkestSecret_;
}