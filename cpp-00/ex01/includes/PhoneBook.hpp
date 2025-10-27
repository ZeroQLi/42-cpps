/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:18 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/27 12:00:00 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <locale>
#include <cstdlib>

class PhoneBook {
	private:
		Contact	contacts[8];
		int		current;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);
		void	addNumber(std::string msg);
		void	addString(std::string msg, int i);
};