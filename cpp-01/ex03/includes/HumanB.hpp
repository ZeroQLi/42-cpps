#include "../includes/Weapon.hpp"

class HumanB
{
private:
	Weapon		*hand;
	std::string	name;
public:
	HumanB(std::string givenName);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &givenHand);
};
