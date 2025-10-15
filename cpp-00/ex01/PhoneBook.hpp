/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:25:18 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:29:38 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook {
	private:
		Contact	contacts[8];
		int		current;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	addContact(void);
		void	searchContact(void);
};

#endif