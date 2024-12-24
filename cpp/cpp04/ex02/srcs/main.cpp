#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	// const AAnimal *animal = new AAnimal();
	// const WrongAnimal *wrongAnimal = new WrongAnimal();
	std::cout << "====================" << std::endl;
	Dog dog = Dog();
	Cat cat = Cat();//deep copyできてるか確認
	std::cout << "====================" << std::endl;
	const AAnimal* animals[] = {new Dog(), new Dog(dog), new Cat(), new Cat(cat)};
	std::cout << "====================" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
		std::cout << std::endl;
	}
	std::cout << "====================" << std::endl;
	return 0;
}

__attribute__((destructor)) void end(void)
{
	system("leaks -q Animal");
}