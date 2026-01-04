#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	delete j; // should not create a leak
	delete i;

	return 0;
}