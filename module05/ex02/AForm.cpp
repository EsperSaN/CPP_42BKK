/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:34:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/05 10:41:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::ostream &operator<<(std::ostream	&o,	AForm	&Aform)
{
	o << "AForm : " << Aform.getName() << "\nRequire Excute : " << Aform.getRequireExe() << "\nRequire	Sign : " << Aform.getRequireGrade() << "\nStatus : " << std::flush;
	if (Aform.getStatus())
		o << "Signed" << std::endl;
	else
		o << "Unsigned" << std::endl;
	Aform.getName();
	return (o);
}

AForm::AForm(void) : _name(FDEF_NAME), _signed(false) ,_reqGrade(FLOWEST_GRADE)	,_reqExe(FLOWEST_GRADE)
{
	// std::cout << FDEF_CON << std::endl << *this << std::flush;
}

AForm::AForm(std::string	name, int	reqGrade, int	reqExe) : _name(name), _signed(false) ,  _reqGrade(reqGrade), _reqExe(reqExe)
{
	// std::cout << FATT_CON << std::endl;
	if (this->_reqExe < FMAXIMUM_GRADE || this->_reqGrade < FMAXIMUM_GRADE)
		throw	AForm::GradeTooHighException();
	if (this->_reqExe > FLOWEST_GRADE || this->_reqGrade > FLOWEST_GRADE)
		throw	AForm::GradeTooLowException();
}

AForm::AForm(std::string	name, int	reqGrade, int	reqExe,	int	sign) : _name(name), _signed(sign),_reqGrade(reqGrade), _reqExe(reqExe)
{
	// std::cout << this->getName() << " : "<< FATT_CON << std::endl;
	if (this->_reqExe < FMAXIMUM_GRADE || this->_reqGrade < FMAXIMUM_GRADE)
		throw	AForm::GradeTooHighException();
	if (this->_reqExe > FLOWEST_GRADE || this->_reqGrade > FLOWEST_GRADE)
		throw	AForm::GradeTooLowException();
}

AForm::AForm(AForm &other) : _name(other.getName()), _signed(other.getStatus()), _reqGrade(other.getRequireGrade()), _reqExe(other.getRequireExe())
{
	// std::cout << FCPY_CON << std::endl;
	// std::cout	<< this << std::endl;
}

AForm::~AForm(void)
{
	// std::cout << FDE_CON << this->_name << std::endl;
}

AForm	&AForm::operator=(const	AForm	&rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

void	AForm::beSigned(Bureaucrat	&who)
{
	if (who.getGrade() > this->_reqGrade)
		throw	(AForm::GradeTooLowException());
	else
		this->_signed = true;
}

bool	AForm::getStatus(void) const
{
	return (this->_signed);
}

int	AForm::getRequireGrade(void)
{
	return (this->_reqGrade);
}

int	AForm::getRequireExe(void) const 
{
	return (this->_reqExe);
}

const	std::string	AForm::getName(void) const
{
	return (this->_name);
}

const	char	*AForm::GradeTooHighException::what() const throw()
{
	return (FTOO_HIGH);
}

const	char	*AForm::GradeTooLowException::what()	const	throw()
{
	return (FTOO_LOW);
}

const	char	*AForm::FormNotSignYet::what()	const	throw()
{
	return (FNOT_SIGN);
}
