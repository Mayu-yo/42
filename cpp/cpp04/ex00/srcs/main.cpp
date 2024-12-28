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
    
    std::cout << "--------------" << std::endl;

    // std::cout << animal->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "--------------" << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "--------------" << std::endl;

    delete meta;
    delete j;
    delete i;

    std::cout << "--- Wrong Test ---" << std::endl;

    const WrongAnimal* wrong = new WrongCat();
    WrongCat wrong2 = WrongCat();

    std::cout << wrong->getType() << " " << std::endl;

    // 猫の鳴き声を出力するはずなのに、動物の鳴き声が出力される
    wrong->makeSound(); 
    wrong2.makeSound();

    std::cout << "--------------" << std::endl;

    delete wrong;

    return 0;
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q Animal");
// }
