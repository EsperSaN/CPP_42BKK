/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 03:02:59 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 17:44:06 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "MyUtil.hpp"

# define PRINTABLE_CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{};\':,.<>/?|\\\" "

class Contact
{
	public :
		Contact();
		~Contact();
		bool addContact();
		void peekContact();
		void showContact();
		bool isAssigned();
	private:
		bool _setEmpty();
		bool _setFirstName();
		bool _setLastName();
		bool _setNickName();
		bool _setPhoneNumber();
		bool _setDarkestSecret();
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
		bool		_assigned;
};

#endif
