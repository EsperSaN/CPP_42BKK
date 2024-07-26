/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/26 15:48:54 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	
	// to LOW Exception!!
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	Bureaucrat	*a;
	try {
		a = new Bureaucrat("The LOWER", 100);
		std::cout	<<	*a	<< std::endl;
		for (int i = 0; i < 100 ; i++)
			a->decrement();

		delete a;
	}
	catch (std::exception &e)
	{
		if (a)
			delete a;
		a = NULL;
		std::cout << "Exception : " <<  e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	try {
		Bureaucrat a("wave", 300);	
		std::cout	<<	a	<< std::endl;
	}
	catch	(std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	// to High exception!!
	try {
		a = new Bureaucrat("The Upper", 100);
		std::cout	<<	*a	<< std::endl;
		for (int i = 0; i < 100 ; i++)
			a->increment();
		delete a;
	}
	catch (std::exception &e)
	{
		if (a)
			delete a;
		a = NULL;
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	try {
		Bureaucrat a("wave", -1);
		std::cout	<<	a	<< std::endl;	
	}
	catch	(std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;	
	// another Exception if it throw!!!
	try {
		a = new Bureaucrat("NULL", -1);
		std::cout	<<	*a	<< std::endl;
		a->increment();
	}
	catch	(std::exception &e)
	{
		if (a)
			delete a;
		a = NULL;
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	Bureaucrat	*t;
	t = NULL;
	try {
		t = new Bureaucrat("WAVE", 0);
		std::cout	<<	*t	<< std::endl;
		std::cout << "test" << std::endl;
		t->increment();
	}
	catch (std::exception	&e)
	{
		if (t)
			delete t;
		t = NULL;
		std::cout	<< e.what() <<  std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;
	// normal right!!!
	Bureaucrat	*w;
	try {
		w = new Bureaucrat("Wave", 1);
		std::cout	<<	*w	<< std::endl;
		for (int i = 0; i < 149 ; i++)
			w->decrement();
		for (int i = 0; i < 149; i++)
			w->increment();
		delete w;
		
	}
	catch (...)
	{
		if (w)
			delete w;
		w = NULL;
		std::cout << "sth wrong!!! <its should not!!!>" << std::endl;
	}
	std::cout << "\n ------------------------------------------------------------\n" << std::endl;

}
