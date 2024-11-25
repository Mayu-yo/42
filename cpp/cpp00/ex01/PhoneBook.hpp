#ifndef PHONE_BOOK
# define PHONE_BOOK

#include "Contact.hpp"

class PhoneBook
{
	private:
   		Contact     _contacts[8];
		// void	_printContact(void);
		void	_displayList(void);
		std::string	_formatString(std::string str);
	public:
		PhoneBook();
		~PhoneBook();
		void	instruction(void);
		void	addContact(void);
		void	searchContact(void);
		void	exitPhoneBook(void);
};

#endif
