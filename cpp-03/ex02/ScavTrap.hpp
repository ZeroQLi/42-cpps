#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "./ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool	gate;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void guardGate();
		void attack(const std::string &target);
		void beRepaired(unsigned int amount);
};

#endif

