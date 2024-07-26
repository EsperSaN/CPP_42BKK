/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:08:48 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/26 16:19:40 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INTERN_HPP
#define	INTERN_HPP

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

class   Intern 
{
    private :
        static  AForm   *getRobo(std::string         target);
        static  AForm   *getShrub(std::string        target);
        static  AForm   *getPresident(std::string    target);
        Intern(const    Intern   &other);
    public :
        Intern(void);

        ~Intern(void);
        Intern  &operator=(const    Intern  &rhs);
        AForm    *makeForm(std::string   formToCreate, std::string   target);
};

#endif
