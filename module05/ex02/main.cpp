/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/22 21:55:25 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

#define	SH	1
#define RB	2
#define PP	3

void	tryEXE(std::string	name, int level, std::string target, int	mode)
{
	std::cout << "\n------------------ TRY EXE -------------------------\n" << std::flush;
	Bureaucrat	*b;
	AForm		*f;

	if (mode == SH)
	{
		try {
			b = new	Bureaucrat(name, level);
			f = new	ShrubberyCreationForm(target);
			std::cout	<< *f << std::endl << *b << std::endl << std::endl;
			b->executeForm(*f);
			b->signForm(*f);
			b->executeForm(*f);
			delete  b;
			delete	f;
		}
		catch(std::exception	&e)
		{
			std::cout << e.what() << std::endl;
			if (b)
				delete b;
			if (f)
				delete f;
		}
	}
	if (mode == RB)
	{
		try {
			b = new	Bureaucrat(name, level);
			f = new	RobotomyRequestForm(target);
			std::cout	<< *f << std::endl << *b << std::endl << std::endl;
			b->executeForm(*f);
			b->signForm(*f);
			b->executeForm(*f);
			delete b;
			delete	f;
		}
		catch(std::exception	&e)
		{
			std::cout << e.what() << std::endl;
			if (b)
				delete b;
			if (f)
				delete f;
		}
	}
	if (mode == PP)
	{
		try {
			b = new	Bureaucrat(name, level);
			f = new	ShrubberyCreationForm(target);
			std::cout	<< *f << std::endl << *b << std::endl << std::endl;
			b->executeForm(*f);
			b->signForm(*f);
			b->executeForm(*f);
			delete b;
			delete	f;
		}
		catch(std::exception	&e)
		{
			std::cout << e.what() << std::endl;
			if (b)
				delete b;
			if (f)
				delete f;
		}
	}
	std::cout << "\n----------------------------------------------------\n" << std::flush;
}

int main()
{
	tryEXE("wave", 1, "test1", SH);
	tryEXE("LEK" , 150, "test2", SH);
	tryEXE("wave", 1, "test1", RB);
	tryEXE("LEK" , 150, "test2", RB);
}
