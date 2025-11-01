#include  "../includes/Zombie.hpp"

int main()
{
	Zombie	*zombie1 = newZombie("john");
	zombie1->announce();
	randomChump("alexander");
	delete zombie1;
	return (0);
}