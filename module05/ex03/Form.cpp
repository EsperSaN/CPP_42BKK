/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 22:20:28 by pruenrua         ###   ########.fr       */
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

Form::Form(void) : _name(FDEF_NAME),	_reqGrade(FLOWEST_GRADE)	,_reqExe(FLOWEST_GRADE)
{
	std::cout << FDEF_CON << std::endl << *this << std::flush;
}

Form::Form(std::string	name, int	reqGrade, int	reqExe) : _name(name),  _reqGrade(reqGrade), _reqExe(reqExe)
{
	std::cout << FATT_CON << std::endl;
	if (this->_reqExe < FMAXIMUM_GRADE || this->_reqGrade < FMAXIMUM_GRADE)
		throw	Form::GradeTooHighException();
	if (this->_reqExe > FLOWEST_GRADE || this->_reqGrade > FLOWEST_GRADE)
		throw	Form::GradeTooLowException();
}

Form::Form(std::string	name, int	reqGrade, int	reqExe,	int	sign) : _name(name), _signed(sign),_reqGrade(reqGrade), _reqExe(reqExe)
{
	std::cout << this->getName() << " : "<< FATT_CON << std::endl;
	if (this->_reqExe < FMAXIMUM_GRADE || this->_reqGrade < FMAXIMUM_GRADE)
		throw	Form::GradeTooHighException();
	if (this->_reqExe > FLOWEST_GRADE || this->_reqGrade > FLOWEST_GRADE)
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

bool	Form::getStatus(void) const
{
	return (this->_signed);
}

int	Form::getRequireGrade(void)
{
	return (this->_reqGrade);
}

int	Form::getRequireExe(void) const 
{
	return (this->_reqExe);
}

const	std::string	Form::getName(void) const
{
	return (this->_name);
}

const	char	*Form::GradeTooHighException::what() const throw()
{
	return (FTOO_HIGH);
}

const	char	*Form::GradeTooLowException::what()	const	throw()
{
	return (FTOO_LOW);
}
