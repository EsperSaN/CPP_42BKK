/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 23:11:25 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

#define PPF_EXE     5
#define PPF_SIGN    25
#define PPFORM_NAME   "PresidentialPardonForm"
#define PP_FORM_DECON "PresidentialPardonForm : Deconstructor Called : PresidentialPardonForm"


class	PresidentialPardonForm : public Form
{
	private :	
		std::string	_target;
        PresidentialPardonForm(void);
		PresidentialPardonForm(std::string	name,	int	reqGrade, int	reqExe);
		PresidentialPardonForm(PresidentialPardonForm	&other);
        PresidentialPardonForm				&operator=(const	PresidentialPardonForm	&rhs);
    public	:
		PresidentialPardonForm(std::string   name);
		~PresidentialPardonForm(void);
		void	execute(class Bureaucrat	const	&executor) const;
};
