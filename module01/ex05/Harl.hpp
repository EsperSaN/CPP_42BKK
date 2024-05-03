/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:02:21 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/03 18:22:28 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define DEBUG_MSG "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MSG "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. "
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};
