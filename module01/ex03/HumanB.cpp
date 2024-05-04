/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:01:40 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/03 23:40:01 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(nullptr)
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	std::cout << "setWeapon called" << std::endl;
	std::cout << "weapon adress : " << &weapon << std::endl;
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (this->_weapon == nullptr)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
	}
	else
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}
