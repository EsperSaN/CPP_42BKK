/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:37:52 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/28 21:08:29 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
	
class Zombie
{
	public	:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		std::string getName(void);
		void setName(std::string name);
	private :
		std::string _name;
};
void randomChump(std::string name);
Zombie *newZombie(std::string name);
Zombie *zombieHord(int N, std::string name);

#endif
