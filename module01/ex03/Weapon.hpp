/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:59:06 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/02 21:53:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon {
	public :
		Weapon();
		Weapon(std::string _type);
		~Weapon();
		std::string		getType();
		void			setType(std::string _type);
	private :
		std::string _type;
};

#endif
