#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_energyPoint = SC_EP;
	this->_attackDamage = SC_ATK;
	std::cout << "ScavTrap Default Constructor : " << this->_name << " the ScavTrap Spawn!!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_energyPoint = SC_EP;
	this->_attackDamage = SC_ATK;
	std::cout << "ScavTrap Name Constructor : " << this->_name << " the ScavTrap Spawn!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy Constructor : " << this->_name << " the ScavTrap Spawn!!" << std::endl;
	*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "ScavTrap Assignment Operator Call : " << this->_name << std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_hitPoint = rhs._hitPoint;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor : " << this->_name << " the ScavTrap Destroy!!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " Cannot attack " << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	std::cout << "ScavTrap " << this->_name << "  attack  " << target << std::flush;
	std::cout << "  , causing  " << this->_attackDamage << "  points of damage!" << std::endl;
}
