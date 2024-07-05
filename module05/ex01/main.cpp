/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/05 10:41:56 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	trySign(std::string	name, int level, std::string form,	int requireLevel)
{
	std::cout << "\n------------------ TRY SIGN -------------------------\n" << std::flush;
	try {
		Bureaucrat	b(name, level);
		Form		f(form, requireLevel, requireLevel);
		
		std::cout	<< f << std::endl << b << std::endl << std::endl;
		b.signForm(f);	
	}
	catch(std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n----------------------------------------------------\n" << std::flush;
}

int main()
{
	trySign("wave", 150 , "DP contact" , 130);
	trySign("wave", 150 , "DP contact" , 199);
	trySign("wave", 150 , "DP contact" , 150);
	trySign("wave", 2 , "DP contact1" , 0);
	trySign("wave", 2 , "DP contact1" , 1);
	
}
