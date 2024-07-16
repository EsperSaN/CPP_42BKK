/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:56:50 by pruenrua          #+#    #+#             */
/*   Updated: 2024/07/05 10:34:38 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

#define SCF_EXE     137
#define SCF_SIGN    145
#define SCF_EXT     "_shrubbery"
#define FORM_NAME   "ShrubberyCreationForm"
#define SH_FORM_DECON "ShrubberyCreationForm : Deconstructor Called : ShrubberyCreationForm"

#define	ATOMIC_TREE "\n\
          .     .  .      +     .      .          .\n\
     .       .      .     #       .           .\n\
        .      .         ###            .      .      .\n\
      .      .   \"#:. .:##\"##:. .:#\"  .      .\n\
          .      . \"####\"###\"####\"  .\n\
       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n\
  .             \"#########\"#########\"        .        .\n\
        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n\
     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n\
                .\"##\"#####\"#####\"##\"           .      .\n\
    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n\
      .     \"#######\"##\"#####\"##\"#######\"      .     .\n\
    .    .     \"#####\"\"#######\"\"#####\"    .      .\n\
            .     \"      000      \"    .     .\n\
       .         .   .   000     .        .       .\n\
.. .. ..................O000O........................ ......"

class	ShrubberyCreationForm : public AForm
{
	private :	
		std::string	_target;
    ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string	name,	int	reqGrade, int	reqExe);
		ShrubberyCreationForm(ShrubberyCreationForm	&other);
    ShrubberyCreationForm				&operator=(const	ShrubberyCreationForm	&rhs);
    public	:
	  	ShrubberyCreationForm(std::string   name);
	  	~ShrubberyCreationForm(void);

		
		void	execute(class Bureaucrat	const	&executor) const;
};
