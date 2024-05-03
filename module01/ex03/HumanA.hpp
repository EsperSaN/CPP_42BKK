/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:56:04 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/02 21:53:24 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "./Weapon.hpp"

class HumanA{
	public :
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void	attack();
	private :
		std::string _name;
		Weapon		&_weapon;
};
#endif
