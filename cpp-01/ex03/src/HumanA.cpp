#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string givenName, Weapon givenHand)
{
	
	this->name = givenName;
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << std::endl;
}