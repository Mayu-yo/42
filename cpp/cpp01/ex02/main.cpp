#include <iostream>

int main() {
	std::string string;
	std::string *stringPTR = &string;
	std::string& stringREF = string;

	string = "HI THIS IS BRAIN";
	std::cout << " - address - " << std::endl;
	std::cout << "string: " << &string << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF << std::endl;

	std::cout << " - value - " << std::endl;
	std::cout << "string: " << string << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	// stringREF = "HI THIS IS BRAIN REF";
	// std::cout << "string: " << string << std::endl;
	return 0;
}