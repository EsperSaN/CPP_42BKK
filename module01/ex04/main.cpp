/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:30:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/05/06 14:05:02 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::fstream in_file;
	std::fstream out_file;

	std::string lineRead;
	std::string leftStr;
	std::string rightStr;
	std::string strToReplace;
	std::string replaceStr;
	std::string resultLine;
	std::string inFileName;
	std::string outFileName;
	std::size_t inLineFound;

	if (ac != 4)
		return (std::cerr << "Invalid number of arguments\naccept only <filename> <string1> <string2>" << std::endl, 1);

	inFileName.assign(av[1]);
	outFileName.assign(av[1]);
	strToReplace.assign(av[2]);
	replaceStr.assign(av[3]);

	if (replaceStr.empty() == true || strToReplace.empty() == true)
		return (std::cerr << "the <string> should not be empty" << std::endl, 1);

	in_file.open(inFileName.c_str(), std::ios::in);
	if (in_file.rdstate() != 0)
		return (std::cerr << "Error: " << inFileName << " cannot be open\ncheck if the file is valid or have correct permission" << std::endl, 1);
	out_file.open((outFileName + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (out_file.rdstate() != 0)
		return (std::cerr << "Error: " << outFileName << ".replace cannot access or somthing went wrong" << std::endl, 1);

	std::getline(in_file, lineRead, '\0');
	std::cout << "read : " << lineRead << std::endl;
	resultLine = lineRead;
	inLineFound = resultLine.find(strToReplace);
	while ((strToReplace != replaceStr) && (inLineFound != std::string::npos))
	{
		leftStr = resultLine.substr(0, inLineFound);
		rightStr = resultLine.substr((inLineFound + strToReplace.length()), resultLine.length());			
		resultLine = leftStr + replaceStr + rightStr;
		inLineFound = rightStr.find(strToReplace);
		if (inLineFound == std::string::npos)
			break;
		inLineFound += leftStr.length() + replaceStr.length();
	}
	std::cout << "here" << std::endl;
	out_file << resultLine << std::flush;
	lineRead.erase();
	resultLine.erase();
	std::cout << resultLine << std::endl;
	in_file.close();
	out_file.close();
}
