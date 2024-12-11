#include "Zombie.hpp"

int main( void ) {
    Zombie zombi1("zom");
    Zombie *zombi2 = newZombie("moz");
    if (!zombi2)
        return 1;
    zombi2->announce();
    delete zombi2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("randi");
    return 0;
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q Zombie");
// }