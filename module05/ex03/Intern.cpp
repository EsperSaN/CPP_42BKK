/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:27:42 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 21:39:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <string>

Intern::Intern(void)
{
	// std::cout << "Intern : Constructor Call" <<  std::endl;
}


Intern::Intern(const	Intern&	other)
{
	// std::cout << "Intern : Copy constructor Call : Intern do Nothing" << std::endl;
    (void)other;
}

Intern	&Intern::operator=(const	Intern&	rhs)
{
    // std::cout << "Intern : Assignment Operator Call" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << "Intern : Deconstructor Called" << std::endl;
}

AForm    *Intern::getRobo(std::string    target)
{
    AForm    *ret;
    
    ret = new RobotomyRequestForm(target);
    return (ret);
}

AForm    *Intern::getShrub(std::string   target)
{
    AForm    *ret;

    ret = new ShrubberyCreationForm(target);
    return (ret);
}

AForm    *Intern::getPresident(std::string    target)
{
    AForm    *ret;
    
    ret = new PresidentialPardonForm(target);
    return (ret);
}

AForm    *Intern::makeForm(std::string   formToCreate, std::string   target)
{
    AForm    *(*function[3])(std::string);
    std::string form[4];
    
    function[0] = &Intern::getPresident;
    function[1] = &Intern::getRobo;
    function[2] = &Intern::getShrub;
    form[1] = "robotomy request";
    form[0] = "presidential pardon";
    form[2] = "shrubbery creation";
    
	int i = 0;
    while (i < 3)
    {
		if (form[i] == formToCreate)
		{
			std::cout << "Intern creates " << formToCreate << std::endl;
			return (function[i](target));
		}
		i++;
    }
    std::cout << "Intern Error : Cannot create the " << formToCreate << std::endl;
    return (NULL);
}

