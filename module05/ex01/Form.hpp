/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/03 16:32:05 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

#define GTOO_HIGH	"The Grade is too high!!!"
#define	GTOO_LOW	"The Grade is too low !!!"

#define FDEF_CON	"Form void Constructor Called : "
#define	FATT_CON "Form Attribute Constructor Called : "
#define	FDE_CON	"Form Deconstructor Called : "
#define	FCPY_CON	"Form Copy Constructor Called : "
#define	FAS_OP	"Form Assignment Operator Called : "


class	Form
{
	private :	
		const	std::string	_name;
		bool		_signed;
		const	int	_reqGrade;
		const	int	_reqExe;
	public	:
		Form(void);
		Form(std::string	name,	int	reqGrade, int	reqExe);
		Form(Form	&other);
		~Form(void);
		Form				&operator=(const	Form	&rhs);
		
		bool				getStatus(void);
		int					getRequireGrade(void);
		int 				getRequireExe(void);
		const	std::string	getName(void);
		
		void				beSigned(Bureaucrat	&who);

		class	GradeTooHighException	:	public	std::exception
		{
     	   public:
        	    virtual const char* what() const throw() { return GTOO_HIGH; }
		};
		class	GradeTooLowException	:	public	std::exception
		{
        	public:
            	virtual const char* what() const throw() { return GTOO_LOW; }
		};
};

std::ostream	&operator<<(std::ostream	&o,	Form	&form);
