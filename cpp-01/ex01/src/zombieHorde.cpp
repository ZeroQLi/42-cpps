#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 1 || N > 2147483647)
	{
		std::cerr << "ERROR: invalid number\n";
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name);
	return (horde);
}
