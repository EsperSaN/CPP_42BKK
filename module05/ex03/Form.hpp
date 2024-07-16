/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 23:09:54 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "./Bureaucrat.hpp"

//class forward declaration


#define FTOO_HIGH	"Form : The Grade is too high!!!"
#define	FTOO_LOW	"Form : The Grade is too low !!!"

#define FDEF_CON	"Form : void Constructor Called : "
#define	FATT_CON "Form : Attribute Constructor Called : "
#define	FDE_CON	"Form : Deconstructor Called : "
#define	FCPY_CON	"Form : Copy Constructor Called : "
#define	FAS_OP	"Form : Assignment Operator Called : "

#define	FLOWEST_GRADE 150
#define	FMAXIMUM_GRADE	1
#define	FDEF_NAME "Default contact"


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
		Form(std::string	name, int	reqGrade, int	reqExe,	int	sign);
		Form(Form	&other);
		virtual	~Form(void);
		Form				&operator=(const	Form	&rhs);
		
		bool				getStatus(void) const;
		int					getRequireGrade(void);
		int 				getRequireExe(void) const;
		const	std::string	getName(void)	const ;
		
		void				beSigned(class Bureaucrat	&who);
		virtual	void		execute(class Bureaucrat	const	&executor) const = 0;
		class	GradeTooHighException	:	public	std::exception
		{
     	   public:
        	    virtual const char* what() const throw();
		};
		class	GradeTooLowException	:	public	std::exception
		{
        	public:
            	virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream	&o,	Form	&form);
