/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:15 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:56:53 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	current = 0;
}

void PhoneBook::addContact(void)
{
	std::string input;

	std::cout << "Enter first name: ";
	getline(std::cin, input);
	std::cout << "You entered: " << input << std::endl;
}

int main(void)
{
	PhoneBook		Book;
	std::string		input;
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