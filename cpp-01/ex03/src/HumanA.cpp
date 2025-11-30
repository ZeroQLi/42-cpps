#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string givenName, Weapon &givenHand) : name(givenName), hand(givenHand)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::string melee = hand.getType();
	if (melee.length() == 0)
	{
		std::cout << name << " attacks with... Nothing??" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << melee << std::endl;
}