#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << ": RAHHHHH you got me, i'll get you next time\n";
}

void Zombie::announce( void )
{
	std::cout << this->name << ": Braiiiiiiinnnssss...\n";
}