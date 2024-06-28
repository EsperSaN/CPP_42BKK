#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "Claptrap.hpp"
#define SC_EP 50
#define SC_ATK 20

class	ScavTrap : public ClapTrap 
{
	public :
	// OC
		ScavTrap(void);
		ScavTrap(std::string	name);
		ScavTrap(const	ScavTrap&	other);
		~ScavTrap(void);
		ScavTrap	&operator=(const	ScavTrap&	rhs);
	// Methods
		void	attack(const	std::string&	target);
		void	guardGate(void);
};

#endif
