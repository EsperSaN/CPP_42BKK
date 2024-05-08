/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:25:08 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/08 22:34:14 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

Claptrap::Claptrap(void) : _name("Claptrap"), _hitPoints(100), _energyPoints(100), _attackDamage(0) {
	std::cout << "Claptrap default constructor called" << std::endl;
}

Claptrap::Claptrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(100), _attackDamage(0) {
	std::cout << "Claptrap name constructor called" << std::endl;
}

Claptrap::Claptrap(const Claptrap& other) {
	std::cout << "Claptrap copy constructor called" << std::endl;
	*this = other;
}

Claptrap::~Claptrap(void) {
	std::cout << "Claptrap destructor called" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount) {
	std::cout << "Claptrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void Claptrap::attack(std::string const& target) {
	this->_energyPoints -= 1;
	std::cout << "Claptrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount) {
	std::cout << "Claptrap " << this->_name << " be repaired " << amount << " points!" << std::endl;
	if (this->_energyPoints <= 0)
	{
		std::cout << "Claptrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}