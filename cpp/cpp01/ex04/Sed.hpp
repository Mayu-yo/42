#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
	public:
		Sed(std::string filename, std::string s1, std::string s2);
		~Sed(void);
		int replace(void);

	private:
		std::string _filename; 
		std::string _before_string;
		std::string _after_string;
};

#endif
