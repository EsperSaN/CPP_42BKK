/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:18:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/03 18:23:21 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	void (Harl::*functionPtr) (void);
	if (level.compare("DEBUG") != 0 && \
		level.compare("INFO") != 0 && \
		level.compare("WARNING") != 0 && \
		level.compare("ERROR") != 0)
	{
		std::cout << "Invalid level" << std::endl;
		return ;
	}
	switch(level[0])
	{
		case 'D':
			functionPtr =  &Harl::debug;
			break;
		case 'I':
			functionPtr =  &Harl::info;
			break;
		case 'W':
			functionPtr	= &Harl::warning;
			break;
		default :
			functionPtr = &Harl::error;
			break;	
	}
	(this->*functionPtr)();
}

void Harl::debug(void)
{
	std::cout << DEBUG_MSG << std::endl;
}

void Harl::info(void)
{
	std::cout << INFO_MSG << std::endl;
}

void Harl::warning(void)
{
	std::cout << WARNING_MSG << std::endl;
}

void Harl::error(void)
{
	std::cout << ERROR_MSG << std::endl;
}
