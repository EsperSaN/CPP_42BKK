/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 03:08:21 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 22:28:35 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	_setEmpty();
}

Contact::~Contact()
{
	_setEmpty();
}

bool Contact::_setEmpty()
{
	_firstName.erase();
	_lastName.erase();
	_nickName.erase();
	_phoneNumber.erase();
	_darkestSecret.erase();
	_assigned = false;
	return (false);
}

bool Contact::_setFirstName()
{
	std::string firstNameInput;

	while (true) {
		firstNameInput = MyUtil::getLineAndTrim("Enter first name: ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			std::cout << "EOF found!!! please rerun the ADD command!!!" << std::endl;
			firstNameInput.erase();
			return (false);
		}
		else if (firstNameInput.empty() == true)
			std::cout << "First name cannot be empty try again" << std::endl;
		else if (firstNameInput.find_first_not_of(PRINTABLE_CHARSET) != std::string::npos)
			std::cout << "First name must be alphabet and digit only try again" << std::endl;
		else
			break;
	}
	_firstName.assign(firstNameInput);
	return (true);
}

bool Contact::_setLastName()
{
	std::string lastNameInput;

	while (true) {
		lastNameInput = MyUtil::getLineAndTrim("And last name ??? : ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			std::cout << "EOF found!!! please rerun the ADD command!!!" << std::endl;
			lastNameInput.erase();
			return (false);
		}
		else if (lastNameInput.empty() == true)
			std::cout << "Last name cannot be empty try again" << std::endl;
		else if (lastNameInput.find_first_not_of(PRINTABLE_CHARSET) != std::string::npos)
			std::cout << "Last name must be alphabet and digit only try again" << std::endl;
		else
			break;
	}
	_lastName.assign(lastNameInput);
	return (true);
}

bool Contact::_setNickName()
{
	std::string nickNameInput;

	while (true) {
		nickNameInput = MyUtil::getLineAndTrim("give me your nice nickname!! : ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			std::cout << "EOF found!!! please rerun the ADD command!!!" << std::endl;
			nickNameInput.erase();
			return (false);
		}
		else if (nickNameInput.empty() == true)
			std::cout << "Nickname cannot be empty try again" << std::endl;
		else if (nickNameInput.find_first_not_of(PRINTABLE_CHARSET) != std::string::npos)
			std::cout << "Nickname must be alphabet and digit only try again" << std::endl;
		else
			break;
	}
	_nickName.assign(nickNameInput);
	return (true);
}

bool Contact::_setPhoneNumber()
{
	std::string phoneNumberInput;

	while (true) {
		phoneNumberInput = MyUtil::getLineAndTrim("phone number? : ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			std::cout << "EOF found!!! please rerun the ADD command!!!" << std::endl;
			phoneNumberInput.erase();
			return (false);
		}
		else if (phoneNumberInput.empty() == true)
			std::cout << "Phone number cannot be empty try again" << std::endl;
		else if (MyUtil::isAllDigit(phoneNumberInput) == false)
			std::cout << "Phone number must be all digit try again" << std::endl;
		else
			break;
	}
	_phoneNumber.assign(phoneNumberInput);
	return (true);
}

bool Contact::_setDarkestSecret()
{
	std::string darkestSecretInput;
	std::string darkestSecretBuffer;

	std::cout << "I'm listening... \n *send EOF to STOP telling me*\nWhat is your darkest secret?"
			  << std::endl;
	while (true) {
		darkestSecretInput = MyUtil::getLineAndTrim("> ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			if (darkestSecretBuffer.empty() == true)
				std::cout << "Don't be shyyyy Darkest secret cannot be empty try again"
						  << std::endl;
			else {
				std::cout << "That's all??? anyway thank for trust me!!!" << std::endl;
				break;
			}
			darkestSecretBuffer.erase();
		}
		else {
			darkestSecretBuffer.append(darkestSecretInput);
			darkestSecretBuffer.append("\n");
		}
	}
	darkestSecretBuffer[darkestSecretBuffer.length() - 1] = '\0';
	_darkestSecret.assign(darkestSecretBuffer);
	darkestSecretInput.erase();
	darkestSecretBuffer.erase();
	return (true);
}

bool Contact::addContact()
{
	if (_setFirstName() == false || _setLastName() == false || _setNickName() == false ||
		_setPhoneNumber() == false || _setDarkestSecret() == false) {
		return (_setEmpty(), false);
	}
	_assigned = 1;
	std::cout << "\n\n****** Contact Added ******" << std::endl;
	std::cout << "Firstname     : " << _firstName << std::endl;
	std::cout << "Lastname      : " << _lastName << std::endl;
	std::cout << "Nickname      : " << _nickName << std::endl;
	std::cout << "Phone number  : " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
	return (true);
}

bool Contact::isAssigned()
{
	if (_assigned == false)
		return (false);
	return (true);
}

void Contact::showContact()
{
	std::cout << " > Firstname     : " << _firstName << std::endl;
	std::cout << " > Lastname      : " << _lastName << std::endl;
	std::cout << " > Nickname      : " << _nickName << std::endl;
	std::cout << " > Phone number  : " << _phoneNumber << std::endl;
	std::cout << "****** Darkest secret ******\n" << _darkestSecret << std::endl;
}

void Contact::peekContact()
{
	std::string firstNamepeek;
	std::string lastNamePeek;
	std::string nickNamePeek;

	firstNamepeek.assign(_firstName);
	lastNamePeek.assign(_lastName);
	nickNamePeek.assign(_nickName);

	if (firstNamepeek.length() > 10) {
		firstNamepeek.resize(9);
		firstNamepeek.append(".");
	}
	if (lastNamePeek.length() > 10) {
		lastNamePeek.resize(9);
		lastNamePeek.append(".");
	}
	if (nickNamePeek.length() > 10) {
		nickNamePeek.resize(9);
		nickNamePeek.append(".");
	}
	std::cout << std::setw(10) << firstNamepeek << "|";
	std::cout << std::setw(10) << lastNamePeek << "|";
	std::cout << std::setw(10) << nickNamePeek << "|" << std::endl;

	firstNamepeek.erase();
	lastNamePeek.erase();
	nickNamePeek.erase();
}
