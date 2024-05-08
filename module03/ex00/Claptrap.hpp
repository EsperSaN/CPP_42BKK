/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:00:58 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/08 22:00:40 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class Claptrap {
	
	public :
		Claptrap(void);
		Claptrap(std::string name);
		~Claptrap(void);
		Claptrap(const Claptrap &src);
		Claptrap& operator=(const Claptrap &rightSide);
		
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private :
		std::string _name;
		int 		_hitPoints;
		int 		_energyPoints;
		int 		_attackDamage;
};

Claptrap::Claptrap(void) : _name("Claptrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap default constructor called" << std::endl;
}

Claptrap::Claptrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap name constructor called" << std::endl;
}

Claptrap::~Claptrap(void)
{
	std::cout << "Claptrap destructor called" << std::endl;
}

Claptrap::Claptrap(const Claptrap &src)
{
	*this = src; // copy by assignment overload
	std::cout << "Claptrap copy constructor called" << std::endl;
}

Claptrap& Claptrap::operator=(const Claptrap& rightSide)
{
	if (this != &rightSide)
	{
		this->_name = rightSide._name;
		this->_hitPoints = rightSide._hitPoints;
		this->_energyPoints = rightSide._energyPoints;
		this->_attackDamage = rightSide._attackDamage;
	}
	std::cout << "Claptrap copy assignment operator called" << std::endl;
	return *this;
}

void Claptrap::attack(std::string const &target)
{
	std::cout << "Claptrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints - amount;
	std::cout << "Claptrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints + amount;
	std::cout << "Claptrap " << this->_name << " be repaired " << amount << " points!" << std::endl;
}

#endif
