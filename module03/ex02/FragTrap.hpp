#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "Claptrap.hpp"
#define FT_EP 100
#define FT_ATK 30

class	FragTrap : public ClapTrap 
{
	public :
		FragTrap(void);
		FragTrap(std::string	name);
		FragTrap(const	FragTrap&	other);
		~FragTrap(void);
		FragTrap	&operator=(const	FragTrap&	rhs);
		void	highFivesGuys(void);
};

#endif
