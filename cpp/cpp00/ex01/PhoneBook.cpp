#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::instruction(void) {
	std::cout << "Welcome to my PhoneBook!" << std::endl;
	std::cout << "--- USAGE ---" << std::endl;
	std::cout << "You can use the following 3 commands." << std::endl;
	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT:	The program quits and the contacts are lost forever!" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact() {
	static int	i = 0;

	_contacts[i % 8].fillin(i % 8);
	i++;
	std::cout << "successfully added." << std::endl;
}

void	PhoneBook::_displayList() {
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		_contacts[i].printContact(_contacts[i]);
	}
}

void	PhoneBook::searchContact() {
	std::string	_input;
	int		_index;

	_displayList();
	while (1)
	{
		_input = getInput("Please enter the index of the contact you want to see.");
		printf("input: %s\n", _input.c_str());
		if (_input.length() == 1 && _input[0] >= '1' && _input[0] <= '8')
		{
			_index = std::stoi(_input);
			printf("index: %d\n", _index);
			_contacts[_index - 1].printDetail(_contacts[_index - 1]);
			break;
		}
		else
			std::cout << "Invalid index." << std::endl;
	}
}
