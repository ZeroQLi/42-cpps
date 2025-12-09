#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void): name("noName"), hp(10), ep(10), atk(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), ep(10), atk(0)
{
	std::cout << "constructor called with name: " << name << std::endl;
	return;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other): name(other.name), hp(other.hp), ep(other.ep), atk(other.atk)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->atk = other.atk;
	}
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->ep > 0 && this->hp > 0)
	{
		if (target.empty())
			std::cout << "ClapTrap " << this->name << " cannot attack. No weapon\n";
		else
		{
			std::cout << "ClapTrap " << this->name << " attacks " << target <<", causing " << this->atk <<" points of damage!\n";
			this->ep--;
		}
	}
	else if (this->hp > 0)
		std::cout << "ClapTrap " << this->name << "'s attack fails. No energy points.\n";
	else
		std::cout << "ClapTrap " << this->name << "'s attack fails. Not enough hit points.\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp > amount)
		this->hp -= amount;
	else if (this->hp == 0)
	{
		std::cout << "Attack fails as ClapTrap " << this->name << " is already dead.\n";
		return ;
	}
	else
		this->hp = 0;
	std::cout << "ClapTrap " << this->name << " is hit!!! Lost " << amount << " hit points. " << this->hp << " HP remains.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep == 0)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! No Energy points.\n";
	else if (this->hp == 0)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Already dead.\n";
	else if (this->hp == 10)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Already at 10 health points.\n";
	else if (this->hp + amount > 10)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Amount greator than required.\n";
	else
	{
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " repairs by " << amount << " health points. Total points: " << this->hp << std::endl;
	}
}

