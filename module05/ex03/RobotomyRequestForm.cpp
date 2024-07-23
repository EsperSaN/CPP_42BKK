/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 23:11:38 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form(RBFORM_NAME, RBF_SIGN, RBF_EXE)
{
	std::cout << this->getName() << " : "<< FDEF_CON << std::endl << *this << std::flush;
}

RobotomyRequestForm::RobotomyRequestForm(std::string	name) : Form(RBFORM_NAME, RBF_SIGN, RBF_EXE)
{
	this->_target = name;
    std::cout << this->getName() << " : "<< FATT_CON << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RB_FORM_DECON << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const	RobotomyRequestForm	&rhs)
{
    //all the value should not be copy!!!
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm	&other) : Form(other.getName(), other.getRequireGrade(), other.getRequireExe(), other.getStatus())
{    
}

void	RobotomyRequestForm::execute(Bureaucrat	const	&executor) const
{
	int         rint;
    std::srand(time(NULL));

	if (this->getRequireExe() > executor.getGrade())
	{
        rint = std::rand();
        if ((rint % 2) == 1)
            std::cout << this->_target << " has been robotomized" << std::endl;
        else
            std::cout << this->_target << " failed" << std::endl;
	}
	else
        throw (Form::GradeTooLowException());
}