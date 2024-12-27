#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(void);
	Brain(const Brain &rhs);
	Brain &operator=(Brain const &rhs);
	~Brain(void);
};

#endif
