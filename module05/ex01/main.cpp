/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/03 16:35:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include	"Form.hpp"

int main()
{
	try {
		Bureaucrat	*a = new Bureaucrat("wave", 2);
		Form		*f = new Form("rubber", 6, 1);
		std::cout << "here" << std::endl;
		a->signForm(*f);
		std::cout	<< *f << std::endl;
		delete	a;
		delete	f;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
