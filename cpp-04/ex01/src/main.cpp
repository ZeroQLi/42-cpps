#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{

	int num = 10;
	const Animal *meta[num];
	for (int i = 0; i < num / 2; i++)
		meta[i] = new Dog();
	for (int i = num / 2; i < num; i++)
		meta[i] = new Cat();
	
	std::cout << "------------------" << std::endl;

	for (int i = 0; i < num; i++)
	{
		// std::cout << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
	}

	std::cout << "------------------" << std::endl;

	for (int i = 0; i < num; i++)
		delete meta[i];

	std::cout << "------------------" << std::endl;

	Dog *a = new Dog();

	a->setIdea(0, "Chase the cat");
	a->setIdea(1, "Eat the bone");
	a->setIdea(23, "Play with the ball");

	Dog *b = new Dog(*a);

	std::cout << "------------------" << std::endl;

	std::cout << "Dog A Idea 0: " << a->getIdea(0) << std::endl;
	std::cout << "Dog A Idea 1: " << a->getIdea(1) << std::endl;
	std::cout << "Dog A Idea 3: " << a->getIdea(3) << std::endl;
	std::cout << "Dog A Idea 23: " << a->getIdea(23) << std::endl << std::endl;

	std::cout << "Dog B Idea 0: " << b->getIdea(0) << std::endl;
	std::cout << "Dog B Idea 1: " << b->getIdea(1) << std::endl;
	std::cout << "Dog B Idea 3: " << b->getIdea(3) << std::endl;
	std::cout << "Dog B Idea 23: " << b->getIdea(23) << std::endl;

	std::cout << "------------------" << std::endl;
	delete a;
	delete b;
	return 0;
}