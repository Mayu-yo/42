#ifndef PHONE_BOOK
# define PHONE_BOOK

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
	private:
   		Contact     _contacts[8];
		void		_displayList(void);
	public:
		PhoneBook();
		~PhoneBook();
		void	instruction(void);
		void	addContact(void);
		void	searchContact(void);
};

#endif
