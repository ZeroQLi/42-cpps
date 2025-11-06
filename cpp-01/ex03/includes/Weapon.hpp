#pragma once

#include <iostream>
#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon(std::string name);
	~Weapon();
	const std::string&	getType();
	void				setType(std::string str);
};

