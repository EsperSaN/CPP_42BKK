/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/06 23:11:47 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

#define RBF_EXE     45
#define RBF_SIGN    72
#define RBF_EXT     "_shrubbery"
#define RBFORM_NAME   "RobotomyRequestForm"
#define RB_FORM_DECON "RobotomyRequestForm : Deconstructor Called : RobotomyRequestForm"


class	RobotomyRequestForm : public Form
{
	private :	
		std::string	_target;
        RobotomyRequestForm(void);
		RobotomyRequestForm(std::string	name,	int	reqGrade, int	reqExe);
		RobotomyRequestForm(RobotomyRequestForm	&other);
        RobotomyRequestForm				&operator=(const	RobotomyRequestForm	&rhs);
    public	:
		RobotomyRequestForm(std::string   name);
		~RobotomyRequestForm(void);
		void	execute(class Bureaucrat	const	&executor) const;
};
