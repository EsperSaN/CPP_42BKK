/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:27:42 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/04 02:01:27 by pruenrua         ###   ########.fr       */
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

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	if ((this->_grade - 1) < MAXIMUM_GRADE)
		throw	Bureaucrat::GradeTooHighException();
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::decrement(void)
{
	if ((this->_grade + 1) > LOWEST_GRADE)
		throw	Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade + 1;
}
