/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:51:28 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/03 23:17:04 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHord(int N, std::string name)
{
	Zombie *hord;
	
	hord = new (std::nothrow) Zombie[N];
	
	if (hord == nullptr)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return (nullptr);
	}
	for (int i = 0; i < N ; i++)
		hord[i].setName(name);
	return (hord);
}
