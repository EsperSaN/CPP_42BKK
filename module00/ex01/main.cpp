/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 02:45:05 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 10:02:58 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <csignal>
#include <cstdlib>

#include "PhoneBook.hpp"

#define EXIT_COMMAND "EXIT"
#define ADD_COMMAND "ADD"
#define SEARCH_COMMAND "SEARCH"
#define PROMPT "Enter Command: "

int main()
{
	PhoneBook book;
	std::string inputCommands;

	while (true) {
		inputCommands = MyUtil::getLineAndTrim(PROMPT);
		if (inputCommands != EXIT_COMMAND) {
			if (0 == inputCommands.compare(ADD_COMMAND))
				book.addContact();
			else if (inputCommands == SEARCH_COMMAND)
				book.searchContact();
		}
		else
			break;
		if (std::cin.eof() == true)
			MyUtil::clearEofBit();
		inputCommands.erase();
	}
	return (0);
}
