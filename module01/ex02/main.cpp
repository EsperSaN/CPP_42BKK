/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:50:07 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/03 18:40:39 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "Address of string variable: " << &string << std::endl;
	std::cout << "stringPTR variable: " << stringPTR << std::endl;
	std::cout << "stringREF variable: " << &stringREF << std::endl;
	std::cout << "And then : " << std::endl;
	std::cout << "value of string : " << string << std::endl;
	std::cout << "value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "value of stringREF : " << stringREF << std::endl;
}
