#include "./ClapTrap.hpp"

int main(void)
{
	ClapTrap trap("Tank");
	trap.takeDamage(8);
	trap.takeDamage(2); // Should die
	trap.takeDamage(5);

	trap.beRepaired(1);

	ClapTrap does(trap);
	does.attack("laser");

	ClapTrap meow = trap;
	meow.beRepaired(4);

	ClapTrap boring("spare");
	boring.takeDamage(1);
	return (0);
}