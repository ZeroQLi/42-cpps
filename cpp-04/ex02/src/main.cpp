#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// unccoment to throw error
	// const Animal *meta = new Animal();
	// meta->makeSound();
	// delete meta;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();

	delete j;
	delete i;

	std::cout << std::endl;

	const WrongCat *noCat = new WrongCat();
	noCat->makeSound();

	const WrongAnimal *noAn = new WrongAnimal();
	noAn->makeSound();

	delete noCat;
	delete noAn;
	return 0;
}