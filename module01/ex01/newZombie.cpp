/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:12:51 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/18 22:39:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new(std::nothrow) Zombie(name);
	if (zombie == NULL)
		std::cout << "newZombie: failed to allocate memory" << std::endl;
	return (zombie);
}
