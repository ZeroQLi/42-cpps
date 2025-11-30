#include  "../includes/Zombie.hpp"

int main()
{
	Zombie *heapZombie = zombieHorde(8, "Hebbyjebiies");
	if (!heapZombie)
		return (0);
	for (int i = 0; i < 8; i++)
		heapZombie[i].announce();
	delete [] heapZombie;
	return 0;
}