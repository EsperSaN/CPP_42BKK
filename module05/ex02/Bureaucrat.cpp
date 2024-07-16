/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:27:42 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 21:39:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& os, Bureaucrat	&rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::flush;
	return (os);
}

Bureaucrat::Bureaucrat(void): _name(DEF_NAME) , _grade(LOWEST_GRADE)
{
	std::cout << DEF_CON << this->_name << " : "<< this->_grade <<  std::endl;
}

Bureaucrat::Bureaucrat(std::string	name, int	grade) : _name(name), _grade(grade)
{
	std::cout << ATT_CON << this->_name << " : " << this->_grade << std::endl;
	if (this->_grade < MAXIMUM_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	if (this->_grade > LOWEST_GRADE)
		throw	Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const	Bureaucrat&	other) : _name(other._name), _grade(other._grade)
{
	std::cout << CPY_CON << "Copy From >> " << other._name << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const	Bureaucrat&	rhs)
{
	if (this == &rhs)
		return (*this);
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << DE_CON << this->getName() << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	if ((this->_grade - 1) < MAXIMUM_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade = this->_grade - 1;
	std::cout << "The " << this->getName() << " get promoted to " << this->getGrade() << std::endl; 
}

void	Bureaucrat::decrement(void)
{
	if ((this->_grade + 1) > LOWEST_GRADE)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade + 1;
std::cout << "The " << this->getName() << " get depromoted to " << this->getGrade() << std::endl; 
}

const	char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (TOO_HIGH);
}

const	char	*Bureaucrat::GradeTooLowException::what()	const	throw()
{
	return (TOO_LOW);
}

void	Bureaucrat::signForm(AForm	&formToSign)
{
	try	{
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << formToSign.getName() << std::endl;
	}
	catch (std::exception	&e)
	{
		std::cout << this->getName() << " couldn't sign " << formToSign.getName() << \
		" because " << e.what() << " require Grade : " << formToSign.getRequireGrade() \
		<< " but "  << this->getName() << " have " << this->getGrade() <<std::endl;
	}	
}

void	Bureaucrat::executeForm(AForm	const	&form)
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " execute " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{		
		std::cout << this->getName() << " couldn't execute " << form.getName() << \
		" because " << e.what() << " require Grade : " << form.getRequireExe() \
		<< " but "  << this->getName() << " have " << this->getGrade() <<std::endl;
	}
}
