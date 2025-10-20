/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:15 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/20 19:10:41 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

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
	std::string	input;
	std::string	messages[5] = {"Enter first name: ", "Enter last name: ", "Enter nickname: ", "Enter phone number: ", "Enter darkest secret: "};

	if (!contacts[current].getValue(0).empty())
	{
		while (1)
		{
			std::cout << "Contact at index " << current + 1 << " already exists. Overwrite? (y/n): ";
			std::getline(std::cin, input);
			if (input == "y" || input == "Y")
				break;
			else if (input == "n" || input == "N")
				return;
			else
				std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << messages[i];
		getline(std::cin, input);
		while (input.empty())
		{
			std::cout << "WARNING: Empty input. Please enter again: \n" << messages[i];
			getline(std::cin, input);
		}
		contacts[current].setValue(i, input);
	}
	current = (current + 1) % 8;
}

void	PhoneBook::searchContact(void)
{
	int	index;
	while (1)
	{
		std::cout << "Enter contact index to search: ";
		std::cin >> index;
		if (index < 1 || index > 8)
		{
			std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
			continue;
		}
		break;
	}
	if (contacts[index - 1].getValue(0).empty())
		std::cout << "|           No contact found                | \n";
	else
	{
		std::cout << "|-------------------------------------------| \n";
		std::cout << "|     Index| Full Name| Last Name|  Nickname| \n";
		std::cout << "|-------------------------------------------| \n";
		contacts[index - 1].printContact(index - 1);
		std::cout << std::endl;
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
		else
			std::cout << "Invalid command" << std::endl;
	}
}