/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:26:54 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/21 22:42:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./Intern.hpp"

#define	SH	1
#define RB	2
#define PP	3

void	tryEXE(std::string	name, int level, std::string target, int	mode)
{
	std::cout << "\n------------------ TRY EXE -------------------------\n" << std::flush;
	Bureaucrat	*b;
	Form		*f;

	if (mode == SH)
	{
		try {
			b = new	Bureaucrat(name, level);
			f = new	ShrubberyCreationForm(target);
			std::cout	<< *f << std::endl << *b << std::endl << std::endl;
			b->executeForm(*f);
			b->signForm(*f);
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
	if (mode == RB)
	{
		try {
			b = new	Bureaucrat(name, level);
			f = new	RobotomyRequestForm(target);
			std::cout	<< *f << std::endl << *b << std::endl << std::endl;
			b->executeForm(*f);
			b->signForm(*f);
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
	Intern	wave;

	Form* test = wave.makeForm("shrubbery creation", "42");
	Form*	ff = wave.makeForm("presidential pardon", "42");
	Form*	fg = wave.makeForm("presidentialpardon", "42");
	Bureaucrat	b("wave", 1);

	b.executeForm(*test);
	
	b.executeForm(*ff);
	delete ff;
	delete test;
}