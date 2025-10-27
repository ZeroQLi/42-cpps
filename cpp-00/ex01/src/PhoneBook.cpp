/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:15 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/27 12:10:15 by mtangalv         ###   ########.fr       */
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

void PhoneBook::addNumber(std::string msg)
{
	std::string	input;
	int			flag;
	std::locale	loc;

	flag = 0;
	while (1)
	{
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		while (input.empty())
		{
			std::cout << "WARNING: Empty input. Please enter again: \n"
					  << msg;
			std::getline(std::cin, input);
			if (std::cin.eof())
				return;
		}
		for (int i = 0; i < (int) input.length(); i++)
		{
			if (!isdigit(input[i], loc))
			{
				std::cout << "WARNING: invalid number, please type a valid number (0-9): \n";
				flag = 1;
				break ;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			continue ;
		}
		break;
	}
	contacts[current].setValue(3, input);
}

void	PhoneBook::addString(std::string msg, int i)
{
	std::string	input;

	std::cout << msg;
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}
	while (input.empty())
	{
		std::cout << "WARNING: Empty input. Please enter again: \n" << msg;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	contacts[current].setValue(i, input);
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
			if (std::cin.eof())
			{
				std::cout << std::endl;
				return ;
			}
			if (input == "y" || input == "Y")
				break;
			else if (input == "n" || input == "N")
				return ;
			else
				std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (i == 3)
			PhoneBook::addNumber(messages[i]);
		else
			PhoneBook::addString(messages[i], i);
	}
	current = (current + 1) % 8;
}

void	PhoneBook::searchContact(void)
{
	std::string	input;
	int			index;

	std::cout << "Enter contact index to search: ";
	while (std::getline(std::cin, input))
	{
		if (input.empty())
		{
			std::cout << "Input cannot be empty. Please enter a valid index." << std::endl;
			std::cout << "Enter contact index to search: ";
			continue ;
		}
		index = std::atoi(input.c_str());
		if (index < 1 || index > 8)
		{
			std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
			std::cout << "Enter contact index to search: ";
			continue ;
		}
		break;
	}
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return;
	}
	if (contacts[index - 1].getValue(0).empty())
		std::cout << "|             No contact found              |" << std::endl;
	else
	{
		std::cout << "|-------------------------------------------|\n";
		std::cout << "|     Index| Full Name| Last Name|  Nickname|\n";
		std::cout << "|-------------------------------------------|\n";
		contacts[index - 1].printContact(index - 1);
		std::cout << std::endl;
	}
	std::cin.clear();
}

int	main(void)
{
	PhoneBook		Book;
	std::string		input;
	while (1)
	{
		if (std::cin.eof())
			return (0);
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			Book.addContact();
		else if (input == "SEARCH")
			Book.searchContact();
		else
			std::cout << "Invalid command" << std::endl;
	}
}