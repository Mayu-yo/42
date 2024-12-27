#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat(void);
	~Cat(void);
	Cat(std::string type);
	Cat(const Cat &rhs);
	Cat &operator=(const Cat &rhs);

	void makeSound(void) const;
private:
	Brain* _brain;
};

#endif