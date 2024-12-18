#include "../includes/Animal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // 猫のサウンドを出力する！
    j->makeSound(); // 犬のサウンドを出力する！
    meta->makeSound(); // Animal のサウンドを出力する

    return 0;
}
