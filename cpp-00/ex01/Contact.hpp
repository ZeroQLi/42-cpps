/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtangalv <mtangalv@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:24:56 by mtangalv          #+#    #+#             */
/*   Updated: 2025/10/15 18:29:30 by mtangalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using namespace std;

class Contact {
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
};

#endif
