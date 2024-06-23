#include "Claptrap.hpp"

ClapTrap::ClapTrap(void) : _name(DEFAULT_NAME), _hitPoint(CT_HP) , _energyPoint(CT_EP) , _attackDamage(CT_ATK)
{
	std::cout << "Default Constructor : " << this->_name << " the Claptrap Spawn!!" << std::endl;
}

ClapTrap::ClapTrap(std::string	name) :  _name(name), _hitPoint(CT_HP) , _energyPoint(CT_EP) , _attackDamage(CT_ATK)
{
	std::cout << "Default <NAME> Constructor : " << this->_name << " the Claptrap Spawn!!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Deconstructor : " << this->_name << " deconstructor Call TT" << std::endl;
}

ClapTrap::ClapTrap(const	ClapTrap&	other)
{
	std::cout << "Copy constructor Call : Copying < " << other._name << " >" << std::endl;
	// add the assiggned op
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const	ClapTrap&	rhs)
{
	std::cout << this->_name << ": Assignment Operator Call" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_hitPoint = rhs._attackDamage;
	this->_energyPoint = rhs._energyPoint;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const	std::string&	target)
{
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " Cannot attack " << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	std::cout << "ClapTrap  " << this->_name << "  attack  " << target << std::flush;
	std::cout << "  , causing  " << this->_attackDamage << "  points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned	int	amount)
{
	if (this->_hitPoint <= 0)
		std::cout << "ClapTrap : " << this->_name << " already dead x_x" << std::endl;
	if (this->_hitPoint <= static_cast<int>(amount))
		amount = this->_hitPoint;
	this->_hitPoint -= amount;
	std::cout << "Clap Trap : " << this->_name << " take < " << amount << " > of damege!!!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned	int	amount)
{
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " Cannot repair " << std::endl;
		return ;
	}
	this->_energyPoint -= 1;
	this->_hitPoint += amount;
	std::cout << "ClapTrap  " << this->_name << "  repair  " << amount << std::flush;
	std::cout << "  point of hitpoint!! now it have  " << this->_hitPoint << "  points" << std::endl;
}
