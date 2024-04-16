/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyUtil.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:19:18 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/16 19:32:28 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyUtil.hpp"

std::string MyUtil::stringTrim(std::string str)
{
	std::string toTrim;
	std::size_t frontTrimIndex;
	std::size_t backTrimIndex;
	std::string trimmedString;
	
	toTrim.assign(" \t");
	frontTrimIndex = str.find_first_not_of(toTrim);
	backTrimIndex = str.find_last_not_of(toTrim);
	if (frontTrimIndex == std::string::npos || backTrimIndex == std::string::npos)
		return ("");
	trimmedString = str.substr(frontTrimIndex, (backTrimIndex - frontTrimIndex) + 1);
	return (trimmedString);
}

std::string MyUtil::getLineAndTrim(std::string prompt)
{
	std::string Input;

	std::cout << prompt << std::flush;
	std::getline(std::cin, Input);
	return (stringTrim(Input));
}

void MyUtil::clearEofBit()
{
	clearerr(stdin);
	std::cin.clear();
	std::cout << std::endl;
}

bool MyUtil::isAllDigit(std::string str)
{
	std::size_t i;
	
	i = 0;
	if (str[i] == '+' && str.length() > 1)
		i++;
	while (str[i])
	{
		if (std::isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
