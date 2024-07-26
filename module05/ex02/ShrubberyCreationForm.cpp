/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/05 10:41:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(FORM_NAME, SCF_SIGN, SCF_EXE)
{
	// std::cout << this->getName() << " : "<< FDEF_CON << std::endl << *this << std::flush;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string	name) : AForm(FORM_NAME, SCF_SIGN, SCF_EXE)
{
	this->_target = name;
    // std::cout << this->getName() << " : "<< FATT_CON << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << SH_FORM_DECON << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const	ShrubberyCreationForm	&rhs)
{
    //all the value should not be copy!!!
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm	&other) : AForm(other.getName(), other.getRequireGrade(), other.getRequireExe(), other.getStatus())
{    
}

void	ShrubberyCreationForm::execute(Bureaucrat	const	&executor) const
{
	if (this->getStatus() == false)
	{
		throw (AForm::FormNotSignYet());
	}
	std::fstream	out;
	std::string		outfile;

	if (this->getRequireExe() > executor.getGrade())
	{
		outfile.assign(this->_target);
		outfile.append(SCF_EXT);
		try {
			out.open(outfile.c_str(), std::fstream::out | std::fstream::trunc);
			out << ATOMIC_TREE << std::endl;
			out.close();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what();
		}
	}
	else
		throw (AForm::GradeTooLowException());
}
