/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:08:48 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/09 20:32:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class   Intern 
{
    private :
        static  Form   *getRobo(std::string         target);
        static  Form   *getShrub(std::string        target);
        static  Form   *getPresident(std::string    target);
        Intern(const    Intern   &other);
    public :
        Intern(void);

        ~Intern(void);
        Intern  &operator=(const    Intern  &rhs);
        Form    *makeForm(std::string   formToCreate, std::string   target);
};
