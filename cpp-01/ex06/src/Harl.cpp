#include "../includes/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n";
}
void Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout <<  "cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I would not be asking for more!\n";
}
void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.\n";
}
void Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*switches[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case (0):
			(this->*switches[0])();
			std::cout << "\n";
		case (1):
			(this->*switches[1])();
			std::cout << "\n";
		case (2):
			(this->*switches[2])();
			std::cout << "\n";
		case (3):
			(this->*switches[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}