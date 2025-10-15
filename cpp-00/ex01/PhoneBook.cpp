/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:15 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:31:58 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	Book;
	string		input;
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		if (input == "ADD")
			Book.addContact();
		if (input == "SEARCH")
		{
			std::cout << "You chose SEARCH" << std::endl;
		}
	}
}