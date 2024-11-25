#include "Contact.hpp"

Contact::Contact() {
	this->_index = -1;
}

Contact::~Contact() {}


void    Contact::fillin(int _index) {
	this->_index = _index;
    this->_firstName = getInput("Please enter your first name: ");
    this->_lastName = getInput("Please enter your last name: ");
    this->_nickname = getInput("Please enter your nickname: ");
    this->_phoneNumber = getInput("Please enter your phone number: ");
    this->_darkestSecret = getInput("Please enter your darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::_formatString(std::string str) {
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void	Contact::printContact(const Contact &contact) {
	if (contact._index == -1)
		return ;
	std::cout << std::setw(10) << contact._index + 1 << "|";
	std::cout << std::setw(10) << _formatString(contact._firstName) << "|";
	std::cout << std::setw(10) << _formatString(contact._lastName) << "|";
	std::cout << std::setw(10) << _formatString(contact._nickname) << std::endl;
}

void	Contact::printDetail(const Contact &contact) {
	if (contact._index == -1)
		return ;
	std::cout << "First name: " << contact._firstName << std::endl;
	std::cout << "Last name: " << contact._lastName << std::endl;
	std::cout << "Nickname: " << contact._nickname << std::endl;
	std::cout << "Phone number: " << contact._phoneNumber << std::endl;
	std::cout << "Darkest secret: " << contact._darkestSecret << std::endl;
}