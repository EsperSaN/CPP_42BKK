/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:53:01 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/02 22:08:58 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon()
{
	this->setType("default");
}

Weapon::Weapon(std::string weaponType) : _type(weaponType)
{
	std::cout << "Weapon constructor called" << std::endl;
	std::cout << "weaponType : " << weaponType << std::endl;
}

Weapon::~Weapon()
{
	this->_type.erase();
}

std::string	Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
}
