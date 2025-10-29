#pragma once

#include <string>
#include <cstdlib>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	~Zombie();
	void	announce( void );
};
