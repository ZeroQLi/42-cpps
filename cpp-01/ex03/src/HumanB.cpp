#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string givenName)
{
	this->name = givenName;
	this->hand = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &givenHand)
{
	hand = &givenHand;
}

void HumanB::attack()
{
	if (!hand)
	{
		std::cout << name << " has no weapon to attack with!" << std::endl;
		return;
	}
	std::string melee = hand->getType();
	if (melee.length() == 0)
	{
		std::cout << name << " attacks with... Nothing??" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << melee << std::endl;
}