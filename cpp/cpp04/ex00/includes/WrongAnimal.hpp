#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal //結局これはなにを実装すれば良いの
{
protected:
	std::string _type;

public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &rhs);
	WrongAnimal &operator=(WrongAnimal const &rhs);
	~WrongAnimal(void);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif