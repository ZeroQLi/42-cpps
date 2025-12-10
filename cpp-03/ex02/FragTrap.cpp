#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void) : ClapTrap()
{
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 100;
	this->atk = 30;
	std::cout << "FragTrap constructor called with name: " << name << std::endl;
	return;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	return;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
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
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

// member functions
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name <<": I genuinely don't know why am i doing this but HIGH FIVE\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->ep == 0)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! No Energy points.\n";
	else if (this->hp == 0)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Already dead.\n";
	else if (this->hp == 100)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Already at 100 health points.\n";
	else if (this->hp + amount > 100)
		std::cout << "ClapTrap " << this->name << " cannot be Repaired! Amount greator than required.\n";
	else
	{
		this->hp += amount;
		std::cout << "ClapTrap " << this->name << " repairs by " << amount << " health points. Total points: " << this->hp << std::endl;
	}
}
