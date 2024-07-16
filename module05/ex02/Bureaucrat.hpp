/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:28:02 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 18:56:35 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define	DEF_NAME "Default"
#define	MAXIMUM_GRADE	1
#define	LOWEST_GRADE	150

#define TOO_HIGH "Bureaucrat : The Grade is too high!!!"
#define	TOO_LOW	"Bureaucrat : The Grade is too low!!!"
#define DEF_CON	"Bureaucrat : void Constructor Called : "
#define	ATT_CON "Bureaucrat : Attribute Constructor Called : "
#define	DE_CON	"Bureaucrat : Deconstructor Called : "
#define	CPY_CON	"Bureaucrat : Copy Constructor Called : "
#define	AS_OP	"Bureaucrat : Assignment Operator Called : "

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
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		signForm(class AForm &AformToSign);
		void		executeForm(class AForm const & form);

	class	GradeTooHighException : public std::exception
	{
        public:
            virtual const char* what() const throw();
	};
	class 	GradeTooLowException : public std::exception
	{
		public:
            virtual const char* what() const throw();
	};
};
std::ostream&	operator<<(std::ostream& os, Bureaucrat	&rhs);
