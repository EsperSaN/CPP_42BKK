/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:21:58 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/02 22:18:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"
#include "./HumanB.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	std::cout << "club address: " << &club << std::endl;
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon clubb = Weapon("crude spiked club");
	std::cout << "clubb address: " << &clubb << std::endl;
	HumanB jim("Jim");
	jim.setWeapon(clubb);
	jim.attack();
	clubb.setType("some other type of club");
	jim.attack();
	return (0);
}
