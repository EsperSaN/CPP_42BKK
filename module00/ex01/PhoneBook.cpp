/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:39:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 22:31:29 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstring>
#include <string>
PhoneBook::PhoneBook()
{
	std::cout << PHONEBOOK_WELCOME << std::endl;
	std::cout << "\nMaximum contact are : " << MAX_CONTACTS << std::endl;
	std::cout << "if contact are more than " << MAX_CONTACTS << " we will add to the oldest one\n\n"
			  << std::endl;
	_lastAddIndex = 0;
	_assignedCount = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << PHONEBOOK_EXIT << std::endl;
	std::cout << "PhoneBook is destroyed" << std::endl;
}

void PhoneBook::addContact()
{
	std::cout << ADD_MENU << std::endl << std::endl;
	if (_contact[_lastAddIndex].addContact() == true) {
		_lastAddIndex++;
		_assignedCount++;
		if (_lastAddIndex > MAX_CONTACTS - 1)
			_lastAddIndex = 0;
		std::cout << CONTACT_ADD_SUCCESS << std::endl << std::endl;
	}
	else
		std::cout << CONTACT_ADD_FAIL << std::endl << std::endl;
	return;
}

void PhoneBook::searchContact()
{
	std::string inputIndex;
	int index;

	if (_assignedCount <= 0) {
		std::cout << NO_CONTACT << std::endl << std::endl;
		return;
	}
	std::cout << SEARCH_MENU << std::endl;
	index = 0;
	while (index < MAX_CONTACTS) {
		if (_contact[index].isAssigned() == true) {
			std::cout << "|" << std::setw(10) << (index + 1) << "|" << std::flush;
			_contact[index].peekContact();
		}
		index++;
	}
	std::cout << SEARCH_MENU_END << std::endl << std::endl;
	_getContact();
}

void PhoneBook::_getContact()
{
	std::string inputIndex;

	while (true) {
		inputIndex = MyUtil::getLineAndTrim("Index to Show (1 - 8) : ");
		if (std::cin.eof() == true) {
			MyUtil::clearEofBit();
			std::cout << "EOF found!!! please rerun the command!!!" << std::endl;
			inputIndex.erase();
			return;
		}
		else if (inputIndex.empty() == true)
			std::cout << "Index cannot be empty try again (1 - 8)" << std::endl;
		else if (inputIndex.find_first_not_of("0123456789") != std::string::npos)
			std::cout << "Please Input Number!!! (1 - 8)" << std::endl;
		else if (inputIndex.length() > 1 || (inputIndex[0] - '0') > 8 || (inputIndex[0] - '0') <= 0)
			std::cout << "Index must be between (1 - 8)" << std::endl;
		else if (inputIndex[0] - '0' > _assignedCount)
			std::cout << inputIndex << "  Index is not ADD yet try again" << std::endl;
		else
			break;
	}
	std::cout << SEARCH_MENU_END << std::endl;
	std::cout << "|           Index " << inputIndex << " Contact Detail          |" << std::endl;
	std::cout << SEARCH_MENU_END << std::endl;
	_contact[(inputIndex[0] - '0') - 1].showContact();
	std::cout << SEARCH_MENU_END << std::endl << std::endl;
	inputIndex.erase();
}
