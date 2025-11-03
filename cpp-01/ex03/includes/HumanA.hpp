#include "../includes/Weapon.hpp"

class HumanA
{
private:
	Weapon		hand;
	std::string	name;
public:
	HumanA(std::string givenName, Weapon givenHand);
	~HumanA();
	void	attack();
};
