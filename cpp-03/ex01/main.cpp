#include "./ScavTrap.hpp"

int main(void)
{
	ScavTrap test("tank");
	test.attack("giant laser");
	test.takeDamage(50);
	test.beRepaired(50);

	std::cout << "\n";
	ScavTrap hello("jester");
	hello.beRepaired(10);
	hello.takeDamage(10);
	hello.beRepaired(10);

	std::cout << "\n";
	hello.guardGate();
	hello.guardGate();
	hello.guardGate();
}