/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:39:38 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/28 00:25:44 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define ST_MAX_CONTACTS "8"
# define MAX_CONTACTS 8


#include "Contact.hpp"

# define PHONEBOOK_WELCOME "\
*********************************************\n\
*  Welcome to the PhoneBook Application     *\n\
*  Please use the following commands        *\n\
*                                           *\n\
*  ADD - to add a contact                   *\n\
*  SEARCH - to search a contact             *\n\
*  EXIT - to exit the application           *\n\
*                                           *\n\
*  Please note that command will be         *\n\
*  Discarded if you enter a wrong command   *\n\
*  Have a nice day!                         *\n\
*********************************************"

# define MAX_CONTACTS_REACHED "\
*********************************************\n\
*  Maximum Contact Reached                  *\n\
*  We will add to the oldest one			*\n\
*********************************************"

# define PHONEBOOK_EXIT "\
*********************************************\n\
*  Thank you for using the PhoneBook        *\n\
*  All contact will be deleted              *\n\
*  Have a nice day!                         *\n\
*********************************************"

# define ADD_MENU "\
|-------------------------------------------|\n\
|             Add Contact Menu              |\n\
|-------------------------------------------|"

#define SEARCH_MENU "\
|-------------------------------------------|\n\
|            Search Contact Menu            |\n\
|-------------------------------------------|\n\
|  Index   |First Name| LastName | Nickname |\n\
|----------|----------|----------|----------|"

# define SEARCH_MENU_END "\
|-------------------------------------------|"

# define NO_CONTACT "\
|-------------------------------------------|\n\
|             No contact found!!!           |\n\
|      Please Use ADD Command to ADD one    |\n\
|-------------------------------------------|"

# define CONTACT_ADD_FAIL "\
*********************************************\n\
*     Contact Add Fail Please Add again     *\n\
*********************************************"

# define CONTACT_ADD_SUCCESS "\
|-------------------------------------------|\n\
|         Contact Added Successfully        |\n\
|-------------------------------------------|"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact();
	private:
		void	_getContact();
		int 	_lastAddIndex;
		int		_assignedCount;
		Contact _contact[MAX_CONTACTS];
};

#endif
