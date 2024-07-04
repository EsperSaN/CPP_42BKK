/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/03 16:30:17 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::ostream &operator<<(std::ostream	&o,	Form	&form)
{
	o << "Form : " << form.getName() << "\nRequire Excute : " << form.getRequireExe() << "\nRequire	Sign : " << form.getRequireGrade() << "\nStatus : " << std::flush;
	if (form.getStatus())
		o << "Signed" << std::endl;
	else
		o << "Unsigned" << std::endl;
	form.getName();
	return (o);
}

Form::Form(void) : _name(DEF_NAME),	_reqGrade(LOWEST_GRADE)	,_reqExe(LOWEST_GRADE)
{
	std::cout << FDEF_CON << std::endl << *this << std::flush;
}

Form::Form(std::string	name, int	reqGrade, int	reqExe) : _name(name),  _reqGrade(reqGrade), _reqExe(reqExe)
{
	std::cout	<< FATT_CON << std::endl << *this << std::flush;
	if (this->_reqExe < MAXIMUM_GRADE || this->_reqGrade < MAXIMUM_GRADE)
		throw	Form::GradeTooHighException();
	if (this->_reqExe > LOWEST_GRADE || this->_reqGrade > LOWEST_GRADE)
		throw	Form::GradeTooLowException();
}

Form::Form(Form &other) : _name(other.getName()), _signed(other.getStatus()), _reqGrade(other.getRequireGrade()), _reqExe(other.getRequireExe())
{
	std::cout << FCPY_CON << std::endl;
	std::cout	<< this << std::endl;
}

Form::~Form(void)
{
	std::cout << FDE_CON << this->_name << std::endl;
}

Form	&Form::operator=(const	Form	&rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

void	Form::beSigned(Bureaucrat	&who)
{
	if (who.getGrade() > this->_reqGrade)
		throw	(Form::GradeTooLowException());
	else
		this->_signed = true;
}

bool	Form::getStatus(void)
{
	return (this->_signed);
}

int	Form::getRequireGrade(void)
{
	return (this->_reqGrade);
}

int	Form::getRequireExe(void)
{
	return (this->_reqExe);
}

const	std::string	Form::getName(void)
{
	return (this->_name);
}
