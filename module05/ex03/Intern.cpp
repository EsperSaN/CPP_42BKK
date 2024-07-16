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
	std::cout << DEF_CON <<  std::endl;
}


Intern::Intern(const	Intern&	other)
{
	std::cout << CPY_CON << "Copy From >> " << std::endl;
    (void)other;
}

Intern	&Intern::operator=(const	Intern&	rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << DE_CON << std::endl;
}

Form    *Intern::getRobo(std::string    target)
{
    Form    *ret;
    
    ret = new RobotomyRequestForm(target);
    return (ret);
}

Form    *Intern::getShrub(std::string   target)
{
    Form    *ret;

    ret = new ShrubberyCreationForm(target);
    return (ret);
}

Form    *Intern::getPresident(std::string    target)
{
    Form    *ret;
    
    ret = new PresidentialPardonForm(target);
    return (ret);
}

Form    *Intern::makeForm(std::string   formToCreate, std::string   target)
{
    Form    *(*function[3])(std::string);
    std::string form[3];
    
    function[0] = &Intern::getPresident;
    function[1] = &Intern::getRobo;
    function[2] = &Intern::getShrub;
    form[0] = "robotomyrequestform";
    form[1] = "presidentialpardonform";
    form[2] = "shrubberycreationform";
    
	int i = 0;
    while (formToCreate[i])
    {
		if (form[i] == formToCreate)
			return (function[i](target));
        i++;
    }
    std::cout << formToCreate << "and " << target << std::endl;
    return (NULL);
}

