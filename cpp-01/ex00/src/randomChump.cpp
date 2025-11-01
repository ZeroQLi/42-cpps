#include "../includes/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombs(name);
	zombs.announce();
}