#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB()
{
	if (this->_weapon)
		delete this->_weapon;
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with his bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	if (this->_weapon)
		delete this->_weapon;
	this->_weapon = new Weapon(weapon.getType());
}
