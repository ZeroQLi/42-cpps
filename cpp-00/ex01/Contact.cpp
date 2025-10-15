/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:41:09 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:33:40 by mtangalv         ###   ########.fr       */
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
	
	cout << "Enter first name: ";
	getline(std::cin, input);
	std::cout << "You entered: " << input << std::endl;
}