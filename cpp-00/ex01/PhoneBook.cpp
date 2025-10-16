/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:15 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 20:55:26 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook created!, what have you done" << std::endl;
	current = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destroyed, good riddance!" << std::endl;
}

void	PhoneBook::addContact(void)
{
	std::string input;

	std::string messages[5] = {"Enter first name: ", "Enter last name: ", "Enter nickname: ", "Enter phone number: ", "Enter darkest secret: "};
	for (int i = 0; i < 5; i++)
	{
		std::cout << messages[i];
		getline(std::cin, input);
		contacts[current].setValue(i, input);
	}
	current = (current + 1) % 8;
}

void	PhoneBook::searchContact(void)
{
	int	index;
	std::cout << "Enter contact index to search: ";
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > 8)
		std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
	else
	{
		std::cout << " |-------------------------------------------| \n";
		std::cout << " |     index| Full Name| Last Name|  Nickname| \n";
		std::cout << " |-------------------------------------------| \n";
	}
}

int	main(void)
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
			Book.searchContact();
	}
}