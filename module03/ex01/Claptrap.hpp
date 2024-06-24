#ifndef CLAPTRAP_HPP
# define	CLAPTRAP_HPP

# include <iostream>

# define CT_HP 100
# define CT_EP 10
# define CT_ATK 0
# define DEFAULT_NAME "<no name>"

class ClapTrap 
{
	protected :
		std::string	_name;
		int	_hitPoint;
		int	_energyPoint;
		int	_attackDamage;

	public :
	//	orthrodox chornonical
		ClapTrap(void);
		ClapTrap(std::string	name);
		~ClapTrap(void);
		ClapTrap(const	ClapTrap&	other);
		ClapTrap	&operator=(const	ClapTrap&	rhs);
	// method
		void	attack(const	std::string&	target);
		void	takeDamage(unsigned	int	amount);
		void	beRepaired(unsigned	int	amount);
};

#endif
