#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal &rhs);
	AAnimal &operator=(AAnimal const &rhs);
	virtual ~AAnimal(void);

	virtual void makeSound(void) const = 0;// = 0をつけることで、純粋仮想関数になる
	std::string getType(void) const;
};

#endif
