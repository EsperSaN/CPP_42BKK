/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:28:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/03 15:52:32 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include	"Form.hpp"

class Form;
#define	DEF_NAME "Default"
#define	MAXIMUM_GRADE	1
#define	LOWEST_GRADE	150

#define TOO_HIGH	"The Grade is too high!!!"
#define	TOO_LOW	"The Grade is too low!!!"
#define DEF_CON	"void Constructor Called : "
#define	ATT_CON "Attribute Constructor Called : "
#define	DE_CON	"Deconstructor Called : "
#define	CPY_CON	"Copy Constructor Called : "
#define	AS_OP	"Assignment Operator Called : "

class Bureaucrat
{
	private:
		const	std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string	name, int	grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const	Bureaucrat&	rhs);

		void		increment(void);
		void		decrement(void);
		void		signForm(Form	&formToSign);
		std::string	getName(void);
		int			getGrade(void);

	class	GradeTooHighException : public std::exception
	{
        public:
            virtual const char* what() const throw() { return TOO_HIGH; }
	};
	class	GradeTooLowException : public std::exception
	{
		      public:
            virtual const char* what() const throw() { return TOO_LOW; }
	};
};
std::ostream&	operator<<(std::ostream& os, Bureaucrat	&rhs);


