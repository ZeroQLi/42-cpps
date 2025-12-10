#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();

	void highFivesGuys(void);
	void beRepaired(unsigned int amount);
};

#endif
