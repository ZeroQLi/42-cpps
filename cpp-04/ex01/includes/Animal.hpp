#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType(void) const;
};

#endif

