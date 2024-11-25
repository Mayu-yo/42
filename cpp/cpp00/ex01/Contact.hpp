#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>

std::string	getInput(std::string explanation);

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int _index;
		std::string _formatString(std::string str);
	public:
		Contact();
		~Contact();
		void    fillin(int _index);
		void	printContact(const Contact &contact);
		void	printDetail(const Contact &contact);
	};

#endif