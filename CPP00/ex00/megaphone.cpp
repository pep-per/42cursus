/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:11:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/10/24 22:03:46 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::string str;
	for (int i = 1; i < ac; i ++)
	{
		str = av[i];
		for (size_t j = 0; j < str.size(); j++)
		{
			str[j] = toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}