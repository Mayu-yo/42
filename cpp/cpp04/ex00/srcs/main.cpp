#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound(); 
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    /* Wrong test */
    const WrongAnimal* k = new WrongCat();

    std::cout << k->getType() << " " << std::endl;

    k->makeSound(); // 猫の鳴き声を出力するはずなのに、動物の鳴き声が出力される

    delete k;

    return 0;
}

__attribute__((destructor)) void end(void)
{
	system("leaks -q Animal");
}
