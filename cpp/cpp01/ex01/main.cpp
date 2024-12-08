#include "Zombie.hpp"

int main() {
    Zombie *zombie = zombieHorde(10, "zombi");

    for (int i = 0; i < 10; i++) {
        zombie[i].announce();
    }

    delete [] zombie;
    return 0;
}

// __attribute__((destructor)) void end(void)
// {
// 	system("leaks -q Zombie");
// }