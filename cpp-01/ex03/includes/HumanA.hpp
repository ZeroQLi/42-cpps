#include "../includes/Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		&hand;
public:
	HumanA(std::string givenName, Weapon &givenHand);
	~HumanA();
	void	attack();
};
