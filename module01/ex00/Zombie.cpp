/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:41:22 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/27 20:57:05 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getname(void)
{
	return (this->_name);
}

Zombie::Zombie()
{
	//this->_name.assign("NOOBIE");
	std::cout << "POOR SuMMoNINg " << this->_name << " the Zombae" << std::endl;
}

Zombie::Zombie(std::string _name)
{
	if (_name.empty() == true)
	{
		this->_name.assign("NOOBIE");
		std::cout << "AHHHHHHH YOOOOOOUUU SHOULD GIMMMEE NAMEEE!!!!" << std::endl;
	}
	else
		this->_name.assign(_name);
	std::cout << "Construct " << (*this)._name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " : ArGGAadfadadfa!!!! (" << _name << " the Zombie was slain by Deconstruct) "<< std::endl;
}
