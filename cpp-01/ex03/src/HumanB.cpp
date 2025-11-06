#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string givenName)
{
	this->name = givenName;
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
	std::string melee = (*hand).getType();
	std::cout << name << " attacks with their " << melee << std::endl;
}