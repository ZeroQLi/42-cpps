#ifndef DOG_HPP
# define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog: public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog& other);
		Dog &operator=(const Dog &other);
		~Dog();

		void makeSound() const;

		std::string getIdea(unsigned int index) const;
		void setIdea(unsigned int index, const std::string &idea);
};

#endif

