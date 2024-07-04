/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/04 02:07:02 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	try {
		Bureaucrat	*a = new Bureaucrat("", 100);
		for (int i = 0; i < 10 ; i++)
		{
			a->decrement();
			std::cout << *a << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "not in STD::EXCEPTION" << std::endl;
	}
}
