#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// const AAnimal *animal = new AAnimal();
	// const WrongAnimal *wrongAnimal = new WrongAnimal();
	const AAnimal *animals[] = {new Dog(), new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	return 0;
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q Animal");
// }