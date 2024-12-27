#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat(void);
	Cat(std::string type);
	Cat(const Cat &rhs);
	Cat &operator=(Cat const &rhs);

	void makeSound(void) const;
};

#endif