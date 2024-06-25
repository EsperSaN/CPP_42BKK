
#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_energyPoint = FT_EP;
	this->_attackDamage = FT_ATK;
	std::cout << "FlagTrap Default Constructor : " << this->_name << " the FlagTrap Spawn!!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_energyPoint = FT_EP;
	this->_attackDamage = FT_ATK;
	std::cout << "FlagTrap Name Constructor : " << this->_name << " the FlagTrap Spawn!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FlagTrap Copy Constructor : " << this->_name << " the FlagTrap Spawn!!" << std::endl;
	*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FlagTrap Assignment Operator Call : " << this->_name << std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_hitPoint = rhs._hitPoint;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FlagTrap Destructor : " << this->_name << " the FlagTrap Destroy!!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " High Five" << std::endl;
}
