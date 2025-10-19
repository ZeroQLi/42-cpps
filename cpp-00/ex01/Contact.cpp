/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:41:09 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/17 16:40:37 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setValue(int index, std::string str)
{
	if (index == 0)
		this->first_name = str;
	if (index == 1)
		this->last_name = str;
	if (index == 2)
		this->nickname = str;
	if (index == 3)
		this->phone_number = str;
	if (index == 4)
		this->darkest_secret = str;
}

std::string	Contact::getValue(int index)
{
	if (index == 0)
		return (this->first_name);
	if (index == 1)
		return (this->last_name);
	if (index == 2)
		return (this->nickname);
	if (index == 3)
		return (this->phone_number);
	if (index == 4)
		return (this->darkest_secret);
	return ("");
}

void	Contact::printContact(int index)
{
	std::cout << "|" << std::setw(10) << index;
	for (int i = 0; i < 3; i++)
	{
		std::string field = this->getValue(i);
		if (field.length() > 10)
			field = field.substr(0, 9) + ".";
		std::cout << std::setw(10) << field << "|";
	}
}