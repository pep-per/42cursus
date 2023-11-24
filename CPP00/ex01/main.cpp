/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:05:15 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/11/24 21:41:00 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	std::string cmd;
	while (1) {
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Command [ADD] [SEARCH] : ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			phonebook.addContact();
		}
		else if (cmd == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (cmd == "EXIT" || std::cin.eof())
			break;
	}
	return 0;
}