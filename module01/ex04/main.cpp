/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:30:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/05 02:19:03 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cerr << "Invalid number of arguments\naccept only <filename> <string1> <string2>" << std::endl, 1);
		
	std::fstream in_file;
	std::fstream out_file;
	
	in_file.open(av[1], std::ios::in);
	if (in_file.rdstate() != 0)
		return (std::cerr << "Error: " << av[1] << " not found" << std::endl, 1);

	out_file.open(std::string(av[1]) + ".replace", std::ios::out | std::ios::trunc);
	if (out_file.rdstate() != 0)
		return (std::cerr << "Error: " << av[1] << ".replace cannot be created" << std::endl, 1);
		
	std::string lineRead;
	std::string leftStr;
	std::string rightStr;
	std::string strToReplace = av[2];
	std::string replaceStr = av[3];
	std::string resultLine;
	std::size_t foundIndex;
	
	while (in_file.failbit != true)
	{
		std::getline(in_file, lineRead);
		if (in_file.eof() == true)
			break;
		resultLine = lineRead;
		foundIndex = resultLine.find(strToReplace);
		
		while (strToReplace != replaceStr && foundIndex != std::string::npos)
		{
			leftStr = resultLine.substr(0, foundIndex);
			
			rightStr = resultLine.substr((foundIndex + strToReplace.length()), resultLine.length());
			
			resultLine = leftStr + replaceStr + rightStr;
			std::cout << "herer " << lineRead << std::endl;
		}
		
		out_file << resultLine << std::endl;
		lineRead.erase();
	}
	
}
