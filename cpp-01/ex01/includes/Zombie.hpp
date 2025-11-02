#pragma once

#include <string>
#include <iostream>
#include <new>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce( void );
};

Zombie	*zombieHorde(int N, std::string name);
