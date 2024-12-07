#include "PhoneBook.hpp"

std::string	getInput(std::string explanation) {
	std::string _input;

	std::cout << explanation << std::endl;
	while (1)
	{
		std::getline(std::cin, _input);
		if (!_input.empty())
			break;
		else if (std::cin.eof())
		{
			std::cout << "EOF detected." << std::endl;
			return ("EXIT");
		}
		else
		{
			std::cout << "Please enter something." << std::endl;
		}
	}
	return (_input);
}

int main() {
	PhoneBook book;
	std::string	_input;

	book.instruction();
	while(1)
	{
		_input = getInput("Please enter a command: ");
		if (_input.compare("ADD") == 0)
			book.addContact();
		else if (_input.compare("SEARCH") == 0)
			book.searchContact();
		else if (_input.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	std::cout << "Goodbye!" << std::endl;
	return (0);
}