#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog(void);
	~Dog(void);
	Dog(std::string type);
	Dog(const Dog &rhs);
	Dog &operator=(const Dog &rhs);

	void makeSound(void) const;
private:
	Brain *_brain;
};

#endif