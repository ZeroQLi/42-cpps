#include "./ClapTrap.hpp"

int main(void)
{
	ClapTrap trap("Tank");
	trap.takeDamage(8);
	trap.takeDamage(2); // Should die
	trap.takeDamage(5);
	trap.beRepaired(1);

	std::cout << "\n";
	ClapTrap does(trap);
	does.attack("laser");

	std::cout << "\n";
	ClapTrap meow;
	meow = trap;
	meow.beRepaired(4);

	std::cout << "\n";
	ClapTrap boring("Jet");
	boring.takeDamage(1);
	boring.beRepaired(4);
	boring.beRepaired(1);

	std::cout << "\n";
	boring.attack("");
	boring.attack("giant laser");
	return (0);
}