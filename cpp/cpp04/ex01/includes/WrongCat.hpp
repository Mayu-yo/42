#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &rhs);
	WrongCat &operator=(WrongCat const &rhs);

	void makeSound(void) const;
};

#endif