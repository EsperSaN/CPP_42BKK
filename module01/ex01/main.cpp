/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:13:47 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/19 11:59:17 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z3 = newZombie("Heep z3");
	z3->announce();
	randomChump("randomChump");
	Zombie z4("stack z4");
	Zombie *arrmy;

	arrmy = zombieHord(2, "WAVE");
	//int *a = new int;
	//std::cout << "a = " << a << std::endl;
	delete arrmy;
	delete z3;
	//std::cout << "z3 = " << z3 << "z4 = " << &z4 << std::endl;
}
//std::set_new_handler([]() { std::cout << "new: failed to allocate memory" << std::endl; });
