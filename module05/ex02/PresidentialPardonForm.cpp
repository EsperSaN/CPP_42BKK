/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 21:38:35 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(PPFORM_NAME, PPF_SIGN, PPF_EXE)
{
	std::cout << this->getName() << " : "<< FDEF_CON << std::endl << *this << std::flush;
}

PresidentialPardonForm::PresidentialPardonForm(std::string	name) : AForm(PPFORM_NAME, PPF_SIGN, PPF_EXE)
{
	this->_target = name;
    std::cout << this->getName() << " : "<< FATT_CON << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << PP_FORM_DECON << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const	PresidentialPardonForm	&rhs)
{
    //all the value should not be copy!!!
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm	&other) : AForm(other.getName(), other.getRequireGrade(), other.getRequireExe(), other.getStatus())
{    
}

void	PresidentialPardonForm::execute(Bureaucrat	const	&executor) const
{

	if (this->getRequireExe() > executor.getGrade())
	{
        std::cout << this->_target << " pardoned by Zaphod Beeblebrox" << std::endl;
	}
	else
        throw (AForm::GradeTooLowException());
}
