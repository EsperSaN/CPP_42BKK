/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/05 10:34:38 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AFORM_HPP
#define	AFORM_HPP

#include <iostream>
#include <sstream>
#include "./Bureaucrat.hpp"

//class forward declaration


#define FTOO_HIGH	"Aform : The Grade is too high!!!"
#define	FTOO_LOW	"AForm : The Grade is too low !!!"
#define FNOT_SIGN	"AForm : Form Not Sign Yet!!!"

#define FDEF_CON	"AForm : void Constructor Called : "
#define	FATT_CON "AForm : Attribute Constructor Called : "
#define	FDE_CON	"AForm : Deconstructor Called : "
#define	FCPY_CON	"AForm : Copy Constructor Called : "
#define	FAS_OP	"AForm : Assignment Operator Called : "

#define	FLOWEST_GRADE 150
#define	FMAXIMUM_GRADE	1
#define	FDEF_NAME "Default contact"


class	AForm
{
	private :	
		const	std::string	_name;
		bool		_signed;
		const	int	_reqGrade;
		const	int	_reqExe;
	public	:
		AForm(void);
		AForm(std::string	name,	int	reqGrade, int	reqExe);
		AForm(std::string	name, int	reqGrade, int	reqExe,	int	sign);
		AForm(AForm	&other);
		virtual	~AForm(void);
		AForm				&operator=(const	AForm	&rhs);
		
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
		class	FormNotSignYet : public	std::exception
		{
			public	:
				virtual	const	char*	what()	const throw();
		};
};

std::ostream	&operator<<(std::ostream	&o,	AForm	&Aform);

#endif
