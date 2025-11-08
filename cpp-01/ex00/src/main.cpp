#include  "../includes/Zombie.hpp"

int main()
{
	Zombie	*zombie1 = newZombie("pierce");
	zombie1->announce();
	randomChump("piolo");
	delete zombie1;
	return (0);
}