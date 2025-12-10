#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void): ClapTrap()
{
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hp = 100;
	this->ep = 50;
	this->atk = 20;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
	return;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
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
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

//member functions
void	ScavTrap::attack(const std::string &target)
{
	if (this->ep > 0 && this->hp > 0)
	{
		if (target.empty())
			std::cout << "ScavTrap " << this->name << " cannot attack. No weapon\n";
		else
		{
			std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->atk << " points of damage!\n";
			this->ep--;
		}
	}
	else if (this->hp > 0)
		std::cout << "ScavTrap " << this->name << "'s attack fails. No energy points.\n";
	else
		std::cout << "ScavTrap " << this->name << "'s attack fails. Not enough hit points.\n";
}

void ScavTrap::beRepaired(unsigned int amount)
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

void ScavTrap::guardGate()
{
	if (this->gate == true)
	{
		this->gate = false;
		std::cout << "ScavTrap: " << this->name << " gatekeeper mode: DEACTIVATED\n";
	}
	else
	{
		this->gate = true;
		std::cout << "ScavTrap: " << this->name << " gatekeeper mode: ACTIVATED\n";
	}
}
