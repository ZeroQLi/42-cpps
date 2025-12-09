#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("");
		HumanB jancy("Jancy");
		jancy.attack();
		jancy.setWeapon(club);
		jancy.attack();
		club.setType("giant laser");
		jancy.attack();
		club.setType("some other type of club");
		jancy.attack();
	}
	return 0;
}