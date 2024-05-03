/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:54:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/02 22:07:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

//constructor initializer list:
//CamFeed::CamFeed(ofVideoGrabber& cam) : cam(cam), .... {}
// need to init the list by order in class declearlation to avoid warning and init undefined variable
HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)//constructor initializer list
{
	std::cout << "HumanA constructor called" << std::endl;
	std::cout << "name : " << name << std::endl;
	std::cout << "weapon adress : " << &weapon << std::endl;
	std::cout << "weapon : " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	this->_name.erase();
}

void HumanA::attack()
{
	std::cout << "weapon adress : " << &this->_weapon << std::endl;
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}



