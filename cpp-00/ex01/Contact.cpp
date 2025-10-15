/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:41:09 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:57:00 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::setValue(int index, std::string str)
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