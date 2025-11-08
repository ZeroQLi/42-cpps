#include "../includes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}
void Harl::info(void)
{
	std::cout <<  "cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I would not be asking for more!\n";
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n";
}
void Harl::error(void)
{
	std::cout << "This is unacceptable !I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int j = -1;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			j = i;
			break;
		}
	}
	switch (j)
	{
	case 0:
		Harl::debug();
		break;
	case 1:
		Harl::info();
		break;
	case 2:
		Harl::warning();
		break;
	case 3:
		Harl::error();
		break;
	default:
		std::cout << "Yummy!, no complains at all!\n";
	}
}